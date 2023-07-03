#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "MainObjects/Shelve.hpp"
using namespace std;
User::User(string username_, string password_)
    : Member(username_, password_) { type = USER; }
void User::addShelve(shared_ptr<Shelve> newShelve) { ownShelves.push_back(newShelve); }
void User::deleteRecipeInShelves(shared_ptr<Recipe> recipe)
{
    for (int i = 0; i < ownShelves.size(); i++)
        ownShelves[i]->deleteRecipe(recipe->getId());
}