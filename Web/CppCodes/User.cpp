#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "MainObjects/Shelve.hpp"
using namespace std;
User::User(string username_, string password_)
    : Member(username_, password_) { type = USER; }
void User::addShelve(shared_ptr<Shelve> newShelve) { addSortShelf(ownShelves, newShelve); }
void User::deleteRecipeInShelves(shared_ptr<Recipe> recipe) {
  for (int i = 0; i < ownShelves.size(); i++)
    ownShelves[i]->deleteRecipe(recipe->getId());
}
void addSortShelf(vector<shared_ptr<Shelve>> &shelves, shared_ptr<Shelve> newShelf) {
  for (int i = 0; i < shelves.size(); i++)
    if (shelves[i]->getName() > newShelf->getName()) {
      shelves.insert(shelves.begin() + i, newShelf);
      return;
    }
  shelves.push_back(newShelf);
}