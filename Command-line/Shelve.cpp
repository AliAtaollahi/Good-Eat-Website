#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "MainObjects/Shelve.hpp"
using namespace std;
Shelve::Shelve(int id_, string name_, shared_ptr<Member> owner_)
    : id(id_), name(name_), owner(owner_) {}
int Shelve::getId() const { return id; }
string Shelve::getName() const { return name; }
shared_ptr<Member> Shelve::getOwner() const { return owner; }
void Shelve::addRecipe(shared_ptr<Recipe> newRecipe, shared_ptr<Member> member)
{
    int recipeIndex = search(newRecipe, recipes, Error());
    if (recipeIndex != NOT_FOUND) throw BadRequest();
    recipes.push_back(newRecipe);
}
vector<string> Shelve::getRecipesInfo() const
{
    vector<string> recipesInfo;
    string recipeInfo;
    for (int i = 0; i < recipes.size(); i++)
    {
        if ((recipeInfo = recipes[i]->getInfoInline({})) == "") continue;
        recipesInfo.push_back(recipeInfo);
    }
    return recipesInfo;
}
void Shelve::deleteRecipe(int id)
{
    int recipeIndex = search(id, recipes, BadRequest());
    recipes.erase(recipes.begin() + recipeIndex);
}
bool Shelve::operator==(int id_) const { return (id == id_) ? true : false; }
bool operator==(int id_, const Shelve &shelve_) { return (shelve_.id == id_) ? true : false; }
bool operator==(int id_, shared_ptr<Shelve> shelve_) { return (shelve_->id == id_) ? true : false; }
bool operator==(shared_ptr<Shelve> shelve_, int id_) { return (shelve_->id == id_) ? true : false; }