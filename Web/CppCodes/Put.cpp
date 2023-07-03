#include "SideFuncs/AllFuncs.hpp"
#include "MainObjects/InterFace.hpp"
using namespace std;
void ControlRoom::putShelvesRecipes(int sessionId, int recipeId, string shelfId) {
  if (!isNumber(shelfId)) throw BadRequest();
  int shelfIndex = search(stod(shelfId), allShelves, NotFound());
  if (allShelves[shelfIndex]->getOwner() != allMembers[sessionId]) throw PermissionDenied();
  int recipeIndex = search(recipeId, allRecipes, NotFound());
  allShelves[shelfIndex]->addRecipe(allRecipes[recipeIndex], allMembers[sessionId]);
}
Interface::PutRecipeInShelveHandler::PutRecipeInShelveHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::PutRecipeInShelveHandler::callback(Request *req) {

  string id = req->getQueryParam("recipeId");
  string shelfId = req->getBodyParam("textBoxId");
  Response *res;
  try {
    changeErrorText("");
    cr->putShelvesRecipes(stod(req->getSessionId()), stod(id), shelfId);
    res = Response::redirect("/showRecipeForm?recipeId=" + id);
  }
  catch (Error &e) {
    changeErrorText(e.getText());
    res = Response::redirect("/showRecipeForm?recipeId=" + id);
  }
  return res;
}