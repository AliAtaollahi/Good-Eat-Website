#include "MainObjects/InterFace.hpp"
using namespace std;
int ControlRoom::login(string username, string password) {
  int enteredIndex = search(username, allMembers, NotFound());
  if (allMembers[enteredIndex]->getPassword() != password) throw BadRequest();
  return enteredIndex;
}
void ControlRoom::logout() { deleteFilters(); }
void ControlRoom::postRates(int sessionId, int id, string rating) {
  int recipeIndex = search(id, allRecipes, NotFound());
  if (!isNumber(rating)) throw BadRequest();
  allRecipes[recipeIndex]->addNewRating(stod(rating), allMembers[sessionId]);
}
void ControlRoom::postShelves(int sessionId, string shelfName) {
  shared_ptr<Shelve> newShelve = make_shared<Shelve>(lastShelveId + 1, shelfName, allMembers[sessionId]);
  lastShelveId++;
  allMembers[sessionId]->addShelve(newShelve);
  addSortShelf(allShelves, newShelve);
}
void ControlRoom::postFiltersPos1(string tags) { allFilters[TAG_FILTER]->update(tags); }
void ControlRoom::postFiltersPos2() { allFilters[VEGETERIAN_POS_FILTER]->update(); }
void ControlRoom::postFiltersPos3(string minTime, string maxTime) {
  if (!isNumber(minTime) || !isNumber(maxTime) || minTime == "" || maxTime == "") throw BadRequest();
  allFilters[MIN_FILTER]->update({stod(minTime), stod(maxTime)}, " ", " ");
}
void ControlRoom::postFiltersPos4(string minRate, string maxRate) {
  if (!isNumber(minRate) || !isNumber(maxRate) || minRate == "" || maxRate == "") throw BadRequest();
  allFilters[RATE_FILTER]->update({stod(minRate), stod(maxRate)}, true);
}

void ControlRoom::postRecipes(int sessionId, const vector<string> &arguments_) {
  if (!isNumber(arguments_[MINUTES_TO_READY])) throw BadRequest();
  for (int i = 0; i < arguments_.size(); i++)
    if (arguments_[i] == "") throw BadRequest();
  shared_ptr<Recipe> recipe = make_shared<Recipe>(lastRecipeId + 1, arguments_, allMembers[sessionId]);
  lastRecipeId++;
  allMembers[sessionId]->addRecipes(recipe);
  addSortRecipe(allRecipes, recipe);
}
int ControlRoom::signup(string username, string password, string type) {
  if (username == "" || password == "") throw BadRequest();
  int type_ = search(type, MEMBERS, BadRequest());
  int userIndex = search(username, allMembers, Error());
  if (userIndex != NOT_FOUND) throw BadRequest();
  if (type_ == CHEF) allMembers.push_back(make_shared<Chef>(username, password));
  else if (type_ == USER) allMembers.push_back(make_shared<User>(username, password));
  return allMembers.size() - 1;
}
Interface::LoginPageHandler::LoginPageHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::LoginPageHandler::callback(Request *req) {
  Response *res;
  res = Response::redirect("/");
  changeErrorText("");
  cr->logout();
  res = Response::redirect("/login");
  cout << req->getSessionId() << endl
       << endl
       << endl;
  return res;
}
Interface::LoginHandler::LoginHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::LoginHandler::callback(Request *req) {
  int sessionId;
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");
  Response *res;
  try {
    changeErrorText("");
    sessionId = cr->login(username, password);
    if (cr->getEnteredJob(sessionId) == CHEF) res = Response::redirect("/homeChef");
    else res = Response::redirect("/homeUser");
  }
  catch (Error &e) {
    changeErrorText(e.getText());
    res = Response::redirect("/login");
  }
  res->setSessionId(to_string(sessionId));
  return res;
}
Response *Interface::SignupPageHandler::callback(Request *req) {
  Response *res;
  changeErrorText("");
  res = Response::redirect("/signup");
  return res;
}
Interface::SignupHandler::SignupHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::SignupHandler::callback(Request *req) {
  int sessionId;
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");
  string type_ = req->getBodyParam("type_");
  Response *res;
  try {
    changeErrorText("");
    sessionId = cr->signup(username, password, type_);
    if (type_ == "chef") res = Response::redirect("/homeChef");
    else res = Response::redirect("/homeUser");
  }
  catch (Error &e) {
    changeErrorText(e.getText());
    res = Response::redirect("/signup");
  }
  res->setSessionId(to_string(sessionId));
  return res;
}
Response *Interface::CreateRecipePageHandler::callback(Request *req) {
  Response *res;
  changeErrorText("");
  res = Response::redirect("/createRecipe");
  return res;
}
Interface::PostRecipeHandler::PostRecipeHandler(shared_ptr<ControlRoom> cr_, MyServer *server_) : cr(cr_), server(server_) {}
Response *Interface::PostRecipeHandler::callback(Request *req) {

  string title = req->getBodyParam("title");
  string ingredients = req->getBodyParam("ingredients");
  string minutes_to_ready = req->getBodyParam("minutes_to_ready");
  string tags = req->getBodyParam("tags");
  string vegPos = req->getBodyParam("type_");
  string image = req->getBodyParam("img");
  Response *res;
  try {
    changeErrorText("");
    cr->postRecipes(stod(req->getSessionId()), {title, ingredients, minutes_to_ready, tags, vegPos, image});
    server->get("/" + image, new ShowImage("images/" + image));
    res = Response::redirect("/homeChef");
  }
  catch (Error &e) {
    changeErrorText(e.getText());
    res = Response::redirect("/createRecipe");
  }
  return res;
}
Interface::RatingHandler::RatingHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::RatingHandler::callback(Request *req) {

  string id = req->getQueryParam("recipeId");
  string rating = req->getBodyParam("rate");
  Response *res;
  try {
    changeErrorText("");
    cr->postRates(stod(req->getSessionId()), stod(id), rating);
    res = Response::redirect("/showRecipeForm?recipeId=" + id);
  }
  catch (Error &e) {
    changeErrorText(e.getText());
    res = Response::redirect("/showRecipeForm?recipeId=" + id);
  }
  return res;
}
Interface::AddShelfHandler::AddShelfHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::AddShelfHandler::callback(Request *req) {

  string shelfName = req->getBodyParam("shelfName");
  cr->postShelves(stod(req->getSessionId()), shelfName);
  Response *res = Response::redirect("/myShelves");
  return res;
}
Response *Interface::FiltersPage::callback(Request *req) {
  Response *res;
  changeErrorText("");
  res = Response::redirect("/filters");
  return res;
}
Interface::FiltersHandler::FiltersHandler(shared_ptr<ControlRoom> cr_) : cr(cr_) {}
Response *Interface::FiltersHandler::callback(Request *req) {
  changeErrorText("");
  Response *res;
  try {
    if (req->getBodyParam("time") == "true") cr->postFiltersPos3(req->getBodyParam("time1"), req->getBodyParam("time2"));
    if (req->getBodyParam("rate") == "true") cr->postFiltersPos4(req->getBodyParam("rate1"), req->getBodyParam("rate2"));
    if (req->getBodyParam("tag") == "true") cr->postFiltersPos1(req->getBodyParam("tags"));
    if (req->getBodyParam("vegetarian") == "true") cr->postFiltersPos2();
    res = Response::redirect("/filters");
  }
  catch (Error &e) {
    changeErrorText(e.getText());
    res = Response::redirect("/filters");
  }
  return res;
}