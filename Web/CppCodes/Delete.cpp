#include "MainObjects/InterFace.hpp"
using namespace std;
void ControlRoom::deleteRecipes(int sessionId, string id) {
  int recipeIndex = search(stod(id), allRecipes, NotFound());
  allMembers[sessionId]->deleteRecipeById(allRecipes[recipeIndex]->getId());
  allRecipes.erase(allRecipes.begin() + recipeIndex);
}
void ControlRoom::deleteFilters() {
  for (int i = 0; i < allFilters.size(); i++)
    allFilters[i]->clearFilter();
}
void ControlRoom::deleteShelvesRecipes(int recipeId, int shelfId) {
  int shelfIndex = search(shelfId, allShelves, NotFound());
  allShelves[shelfIndex]->deleteRecipe(recipeId);
}
Interface::DeleteRecipeHandler::DeleteRecipeHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::DeleteRecipeHandler::callback(Request *req) {
  string id = req->getBodyParam("id");

  cr->deleteRecipes(stod(req->getSessionId()), id);
  Response *res = Response::redirect("/homeChef");
  return res;
}
Interface::DeleteFiltersHandler::DeleteFiltersHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::DeleteFiltersHandler::callback(Request *req) {
  changeErrorText("");
  Response *res;
  cr->deleteFilters();
  res = Response::redirect("/filters");
  return res;
}