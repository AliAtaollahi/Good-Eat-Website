#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
using namespace std;
Chef::Chef(string username_, string password_)
    : Member(username_, password_) { type = CHEF; }
void Chef::addRecipes(shared_ptr<Recipe> recipe) { addSortRecipe(madeRecipes, recipe); }
double Chef::getRating(const vector<shared_ptr<Recipe>> &allRecipes) const {
  double sum = 0, allRatedSize = 0;
  for (int i = 0; i < allRecipes.size(); i++)
    if (allRecipes[i]->getChef() == username) {
      sum += allRecipes[i]->getRating();
      if (allRecipes[i]->getRating() != NOT_RATING) allRatedSize++;
    }
  return (allRatedSize == NOT_RATING) ? NOT_RATING : sum / allRatedSize;
}
void Chef::deleteRecipeById(int id) {
  for (int i = 0; i < madeRecipes.size(); i++)
    if (madeRecipes[i] == id) madeRecipes.erase(madeRecipes.begin() + i);
}