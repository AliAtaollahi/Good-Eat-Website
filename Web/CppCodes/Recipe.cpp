#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "SideFuncs/AllFuncs.hpp"
#include "MainObjects/Rating.hpp"
using namespace std;
Rating::Rating(double score_, shared_ptr<Member> recorder_, shared_ptr<Member> chef_, shared_ptr<Recipe> recipe_)
    : score(score_), recorder(recorder_), chef(chef_), recipe(recipe_) {}
Recipe::Recipe(int id_, string title_, vector<string> ingredients_, bool isVegeterian_, int minutes_to_ready_, vector<string> tags_
, string imageAddress_, shared_ptr<Member> chef_): id(id_), title(title_), ingredients(ingredients_), isVegeterian(isVegeterian_)
, minutes_to_ready(minutes_to_ready_), tags(tags_), imageAddress(imageAddress_), chef(chef_) {}
Recipe::Recipe(int id_, const vector<string> arguments, shared_ptr<Member> chef_) {
  vector<string> ingredients = divideLine(arguments[INGREDIENTS], ',');
  vector<string> tags = divideLine(arguments[TAGS], ',');
  int vegeterianPos = search(arguments[TYPE], VEGETERIAN_POS, Error());
  string minutes_to_ready = arguments[MINUTES_TO_READY];
  initiation(id_, arguments[TITLE], ingredients, vegeterianPos, stod(minutes_to_ready), tags, arguments[IMAGE], chef_);
}
string Recipe::getTitle() const { return title; }
int Recipe::getId() const { return id; }
void Recipe::addNewRating(double score, shared_ptr<Member> newRecorder) {
  checkScoreDomain(score);
  for (int i = 0; i < ratings.size(); i++)
    if (ratings[i]->recorder == newRecorder) {
      ratings[i]->score = score;
      return;
    }
  ratings.push_back(make_shared<Rating>(score, newRecorder, chef, shared_from_this()));
}
double Recipe::getRating() const {
  double sum = 0, ratingsSize = 0;
  for (int i = 0; i < ratings.size(); i++) {
    if (ratings[i]->score != NOT_RATING) ratingsSize++;
    sum += ratings[i]->score;
  }
  return (ratingsSize == NOT_RATING) ? NOT_RATING : sum / ratingsSize;
  return 0;
}
shared_ptr<Member> Recipe::getChef() const { return chef; }
bool Recipe::operator==(int id_) const { return (id == id_) ? true : false; }

void Recipe::initiation(int id_, string title_, vector<string> ingredients_, bool isVegeterian_, int minutes_to_ready_, vector<string> tags_
, string imageAddress_, shared_ptr<Member> chef_) {
  id = id_;
  title = title_;
  ingredients = ingredients_;
  isVegeterian = isVegeterian_;
  minutes_to_ready = minutes_to_ready_;
  tags = tags_;
  imageAddress = imageAddress_;
  chef = chef_;
}
void Recipe::checkScoreDomain(double score) const {
  if (score > MAX_SCORE || score < MIN_SCORE) throw BadRequest();
}
string Recipe::getDataForChef() {
  ostringstream body;
  body << "<div style=\"cursor:auto; padding: 10px; border: solid 3px; \">"
       << "<form action=\"/deleteRecipe\" method=\"post\">"
       << "<input name=\"id\" type=\"hidden\" value=\"" << id << "\">"
       << "<button title=\"delete recipe\" class=\"delete\" onclick=\"alert(\\'you delete succusfully!\\');\" type=\"submit\" style=\"cursor"
       << ": pointer;border:none; background: none;\"><img src=\"delete.png\" class=\"delete\"></button>"
       << "</form>"
       << "<img src=\"/" << imageAddress << "\" style=\"height:175px; width:175px; float:left;margin-right: 20px;\">"
       << "Id : " << to_string(id) << "<br>"
       << "Title : " << title << "<br>"
       << "Minutes_to_ready : " << to_string(minutes_to_ready) << "<br>"
       << "Vegeterian : " << VEGETERIAN_POS[isVegeterian] << "<br>"
       << "Tags : " << tags + ","
       << "<br>"
       << "Ingredients : " << ingredients + ","
       << "<br>"
       << "Rate : " << getRating() << "<br>"
       << "</div><br>";
  return body.str();
}
string Recipe::getDataForUser(vector<shared_ptr<Filter>> filters) {
  for (int i = 0; i < filters.size(); i++)
    if (!filters[i]->isPassFromFilter(tags, isVegeterian, minutes_to_ready, getRating())) return "";
  ostringstream body;
  body << "<div style=\"cursor:auto; padding: 10px; border: solid 3px; \">"
       << "<form action=\"/showRecipeForm?recipeId=" << id << "\" method=\"post\">"
       << "<button title=\"recipe info\" type=\"submit\" class=\"delete\">"
       << "<img  src=\"form.jpg\"class=\"delete\" >"
       << "</button>"
       << "<input name=\"id\" type=\"hidden\" value=\"" << id << "\">"
       << "<button title=\"recipe info\" type=\"submit\" style=\"background: none; border: none; height:175px; width:175px; float:left;margin-right"
       << ": 20px;\">"
       << "<img src=\"/" << imageAddress << "\" style=\"cursor:pointer; height:175px; width:175px; float:left;margin-right: 20px;\">"
       << "</button>"
       << "</form>"
       << "Id : " << to_string(id) << "<br>"
       << "Title : " << title << "<br>"
       << "Minutes_to_ready : " << to_string(minutes_to_ready) << "<br>"
       << "Vegeterian : " << VEGETERIAN_POS[isVegeterian] << "<br>"
       << "Tags : " << tags + ","
       << "<br>"
       << "Ingredients : " << ingredients + ","
       << "<br>"
       << "Rate : " << getRating() << "<br>"
       << "</div><br>";
  return body.str();
}
string Recipe::getDataInForm() {
  ostringstream body;
  body << "<div style=\" cursor:auto; padding: 10px; \">"
       << "<img src=\"/" << imageAddress << "\" style=\"height:300px; width:300px;\"><br>"
       << "Title : " << title << "<br>"
       << "Minutes_to_ready : " << to_string(minutes_to_ready) << "<br>"
       << "Vegeterian : " << VEGETERIAN_POS[isVegeterian] << "<br>"
       << "Tags : " << tags + ","
       << "<br>"
       << "Ingredients : " << ingredients + ","
       << "<br>"
       << "Rate : " << getRating() << "<br>"
       << "</div><br>"
       << "<hr>"
       << "<div style=\"width: 305px;\">"
       << "<button title=\"add to shelf\" id=\"changer1\"><img id=\"changer1Img\" src=\"shelf.png\"></button>"
       << "<form action=\"/putRecipeInShelveHandler?recipeId=" << id << "\" method=\"post\">"
       << "<input name=\"id\" type=\"hidden\" value=\"" << id << "\">"
       << "<input name=\"textBoxId\" placeholder=\"shelf id\" id=\"textBoxId\" style=\"visibility: hidden;\" type=\"text\">"
       << "<button id=\"textBoxIdSubmit\" style=\"visibility: hidden;\" type=\"submit\" ><img id=\"send1\" src=\"send.png\"></button>"
       << "</form>"
       << "</div>"
       << "<hr>"
       << "<div style=\" width: 305px;\">"
       << "<button title=\"rate recipe\" id=\"changer2\"><img src=\"rating.png\" id=\"changer2Img\"></button>"
       << "<form action=\"/RatingHandler?recipeId=" << id << "\" method=\"post\">"
       << "<input name=\"id\" type=\"hidden\" value=\"" << id << "\">"
       << "<input name=\"rate\" id=\"rate\" placeholder=\"rating\" style=\"visibility: hidden;\" type=\"text\">"
       << "<button id=\"rateSubmit\" style=\"visibility: hidden;\" type=\"submit\"><img id=\"send2\" src=\"send.png\"></button>"
       << "</form>"
       << "	</div>"
       << "<br>";
  return body.str();
}
string Recipe::getDataForShelf(int shelfId) {
  ostringstream body;
  body << "<div style=\"cursor:auto; padding: 10px; border: solid 3px; \">"
       << "<form action=\"/shelveRecipes\" method=\"post\">"
       << "<input name=\"id\" type=\"hidden\" value=\"" << id << "\">"
       << "<input name=\"shelfId\" type=\"hidden\" value=\"" << shelfId << "\">"
       << "<button title=\"delete recipe from shelf\" class=\"delete\" onclick=\"alert(\"you delete succusfully!\");\" type=\"submit\" style=\"cursor"
       << ": pointer;border:none; background: none;\"><img src=\"delete.png\" class=\"delete\"></button>"
       << "</form>"
       << "<form action=\"/showRecipeForm?recipeId=" << id << "\" method=\"post\">"
       << "<button title=\"recipe info\" type=\"submit\" class=\"delete\">"
       << "<img  src=\"form.jpg\"class=\"delete\" >"
       << "</button>"
       << "<input name=\"id\" type=\"hidden\" value=\"" << id << "\">"
       << "<button type=\"submit\" style=\"background: none; border: none; height:175px; width:175px; float:left;margin-right: 20px;\">"
       << "<img src=\"/" << imageAddress << "\" style=\"cursor:pointer; height:175px; width:175px; float:left;margin-right: 20px;\">"
       << "</button>"
       << "</form>"
       << "Id : " << to_string(id) << "<br>"
       << "Title : " << title << "<br>"
       << "Minutes_to_ready : " << to_string(minutes_to_ready) << "<br>"
       << "Vegeterian : " << VEGETERIAN_POS[isVegeterian] << "<br>"
       << "Tags : " << tags + ","
       << "<br>"
       << "Ingredients : " << ingredients + ","
       << "<br>"
       << "Rate : " << getRating() << "<br>"
       << "</div><br>";
  return body.str();
}
bool operator==(int id_, const Recipe &recipe_) { return (recipe_.id == id_) ? true : false; }
bool operator==(int id_, shared_ptr<Recipe> recipe_) { return (recipe_->id == id_) ? true : false; }
bool operator==(shared_ptr<Recipe> recipe_, int id_) { return (recipe_->id == id_) ? true : false; }