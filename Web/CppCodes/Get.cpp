#include "MainObjects/InterFace.hpp"
using namespace std;
string ControlRoom::getShelves(int sessionId) {
  ostringstream body;
  body << "Your Shelves: <br><br>";
  for (int i = 0; i < allShelves.size(); i++)
    if (allShelves[i]->getOwner() == allMembers[sessionId]) body << allShelves[i]->getRecipesInfo();
  body << "<br><br>";
  return body.str();
}
string ControlRoom::getShelvesRecipes(int shelfId) {
  int shelfIndex = search(shelfId, allShelves, NotFound());
  return allShelves[shelfIndex]->getRecipesForm(shelfId);
}
string ControlRoom::getMyRecipes(int sessionId) {
  ostringstream body;
  body << "Your Rate: " << fixed << setprecision(DIGIT_NUM) << allMembers[sessionId]->getRating(allRecipes) << "<br><br>"
       << "Your recipes:<br><br>";
  for (int i = 0; i < allRecipes.size(); i++)
    if (allRecipes[i]->getChef() == allMembers[sessionId]) body << allRecipes[i]->getDataForChef();
  body << "<img title=\"create new recipe\" onclick=\"add()\" id=\"addImg\" src=\"add.png\">"
       << "<script>function add() { window.location.href = \"/createRecipe\"; }</script>";
  return body.str();
}
string ControlRoom::getAllRecipes() {
  ostringstream body;
  body << "All Recipes: <br><br>";
  for (int i = 0; i < allRecipes.size(); i++)
    body << allRecipes[i]->getDataForUser(allFilters);
  body << "<br>";
  return body.str();
}
string ControlRoom::getRecipeInfo(int id) {
  int recipeIndex = search(id, allRecipes, NotFound());
  ostringstream body;
  body << allRecipes[recipeIndex]->getDataInForm();
  return body.str();
}
string ControlRoom::getShelfIntruduce(int shelfId) {
  int shelfIndex = search(shelfId, allShelves, NotFound());
  ostringstream body;
  body << "Shelve name : " << allShelves[shelfIndex]->getName() << "<br><br>"
       << "Shelve id : " << shelfId << "<br><br>"
       << "recipes : ";
  return body.str();
}
int ControlRoom::getEnteredJob(int sessionId) { return (allMembers[sessionId] == CHEF) ? CHEF : USER; }
void addSortRecipe(vector<shared_ptr<Recipe>> &recipes, shared_ptr<Recipe> newRecipe) {
  for (int i = 0; i < recipes.size(); i++)
    if (recipes[i]->getTitle() > newRecipe->getTitle()) {
      recipes.insert(recipes.begin() + i, newRecipe);
      return;
    }
  recipes.push_back(newRecipe);
}
Interface::homeChefHandler::homeChefHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::homeChefHandler::callback(Request *req) {
  Response *res = new Response;
  changeContentJS(cr->getMyRecipes(stod(req->getSessionId())));
  res = Response::redirect("/homeChefHTML");
  return res;
}
Interface::homeUserHandler::homeUserHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::homeUserHandler::callback(Request *req) {
  Response *res = new Response;
  changeContentJS(cr->getAllRecipes());
  res = Response::redirect("/homeUserHTML");
  return res;
}
Interface::ShowRecipeFormHandler::ShowRecipeFormHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::ShowRecipeFormHandler::callback(Request *req) {
  int currentId = stod(req->getQueryParam("recipeId"));
  Response *res = new Response;
  ostringstream content;
  content << "recipe id : " << currentId << "<br><br>" << cr->getRecipeInfo(currentId);
  changeContentJS(content.str());
  res = Response::redirect("/showRecipeHTML");
  return res;
}
Interface::myShelvesHandler::myShelvesHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::myShelvesHandler::callback(Request *req) {
  Response *res = new Response;
  changeContentJS(cr->getShelves(stod(req->getSessionId())));
  res = Response::redirect("/myShelvesHTML");
  return res;
}
Interface::ShelveRecipes::ShelveRecipes(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::ShelveRecipes::callback(Request *req) {
  string id = req->getBodyParam("id");
  int shelfId = stod(req->getBodyParam("shelfId"));
  if (id != " ") cr->deleteShelvesRecipes(stod(id), shelfId);
  Response *res = new Response;
  ostringstream content;
  content << cr->getShelfIntruduce(shelfId) << "<br><br>" << cr->getShelvesRecipes(shelfId);
  changeContentJS(content.str());
  res = Response::redirect("/shelveRecipesHTML");
  return res;
}
Interface::RecipeFormPageHandler::RecipeFormPageHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::RecipeFormPageHandler::callback(Request *req) {
  string id = req->getQueryParam("recipeId");
  changeErrorText("");
  Response *res = Response::redirect("/showRecipeForm?recipeId=" + id);
  return res;
}