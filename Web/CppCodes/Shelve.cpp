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
void Shelve::addRecipe(shared_ptr<Recipe> newRecipe, shared_ptr<Member> member) {
  int recipeIndex = search(newRecipe, recipes, Error());
  if (recipeIndex != NOT_FOUND) throw BadRequest();
  addSortRecipe(recipes, newRecipe);
}
string Shelve::getRecipesInfo() const {
  ostringstream body;
  body << "<form action=\"shelveRecipes\" method=\"post\">"
       << "<input name=\"shelfId\" type=\"hidden\" value=\"" << id << "\">"
       << "<input name=\"id\" type=\"hidden\" value=\" \">"
       << "<button title=\"shelf info\" type=\"submit\" class=\"settings\"><img style=\"width: 15px; height: 15px;\" src=\"settings.png\"></button>"
       << "<button type=\"button\" class=\"collapsible\">" << name << "</button>"
       << "<div class=\"content\"><br>shelf id : " << id << "<br><br>"
       << "recipes : <br><ul>"
       << "</form>";
  for (int i = 0; i < recipes.size(); i++)
    body << "<li>" << recipes[i]->getTitle() << "</li><br>";
  body << "</ul></div>";
  return body.str();
}
string Shelve::getRecipesForm(int shelfId) {
  ostringstream body;
  for (int i = 0; i < recipes.size(); i++)
    body << recipes[i]->getDataForShelf(shelfId);
  body << "<img title=\"add recipe to shelf\" onclick=\"window.location.href = \\'/homeUser\\';\" id=\"addImg\" src=\"add.png\">";
  return body.str();
}
void Shelve::deleteRecipe(int id) {
  int recipeIndex = search(id, recipes, BadRequest());
  recipes.erase(recipes.begin() + recipeIndex);
}
bool Shelve::operator==(int id_) const { return (id == id_) ? true : false; }
bool operator==(int id_, const Shelve &shelve_) { return (shelve_.id == id_) ? true : false; }
bool operator==(int id_, shared_ptr<Shelve> shelve_) { return (shelve_->id == id_) ? true : false; }
bool operator==(shared_ptr<Shelve> shelve_, int id_) { return (shelve_->id == id_) ? true : false; }