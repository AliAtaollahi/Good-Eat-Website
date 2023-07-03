#include "MainObjects/ControlRoom.hpp"
using namespace std;
int ControlRoom::getEnteredJob(int sessionId) { return (allMembers[sessionId] == CHEF) ? CHEF : USER; }
void addSortRecipe(vector<shared_ptr<Recipe>> &recipes, shared_ptr<Recipe> newRecipe) {
  for (int i = 0; i < recipes.size(); i++)
    if (recipes[i]->getTitle() > newRecipe->getTitle()) {
      recipes.insert(recipes.begin() + i, newRecipe);
      return;
    }
  recipes.push_back(newRecipe);
}
void addSortShelf(vector<shared_ptr<Shelve>> &shelves, shared_ptr<Shelve> newShelf) {
  for (int i = 0; i < shelves.size(); i++)
    if (shelves[i]->getName() > newShelf->getName()) {
      shelves.insert(shelves.begin() + i, newShelf);
      return;
    }
  shelves.push_back(newShelf);
}