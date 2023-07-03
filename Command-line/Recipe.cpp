#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "SideFuncs/AllFuncs.hpp"
#include "MainObjects/Rating.hpp"
using namespace std;
Rating::Rating(double score_, shared_ptr<Member> recorder_, shared_ptr<Member> chef_, shared_ptr<Recipe> recipe_)
    : score(score_), recorder(recorder_), chef(chef_), recipe(recipe_) {}
Recipe::Recipe(int id_, string title_, vector<string> ingredients_, bool isVegeterian_, int minutes_to_ready_
, vector<string> tags_, string imageAddress_, shared_ptr<Member> chef_)
    : id(id_), title(title_), ingredients(ingredients_), isVegeterian(isVegeterian_), minutes_to_ready(minutes_to_ready_)
    , tags(tags_), imageAddress(imageAddress_), chef(chef_) {}
Recipe::Recipe(int id_, const vector<string> arguments, shared_ptr<Member> chef_)
{
    vector<string> ingredients = divideLine(arguments[INGREDIENTS], ',');
    vector<string> tags = divideLine(arguments[TAGS], ',');
    int vegeterianPos = search(arguments[TYPE], VEGETERIAN_POS, Error());
    string minutes_to_ready = arguments[MINUTES_TO_READY];
    initiation(id_, arguments[TITLE], ingredients, vegeterianPos, stod(minutes_to_ready), tags, arguments[IMAGE], chef_);
}

string Recipe::getTitle() const { return title; }
int Recipe::getId() const { return id; }
string Recipe::getInfo() const
{
    ostringstream info;
    info << id << endl
         << title << endl
         << "vegetarian: " << VEGETERIAN_POS[isVegeterian] << endl
         << "ingredients: [" << ingredients + ", " << ']' << endl
         << "minutes to ready: " << minutes_to_ready << endl
         << "tags: [" << tags + ", " << ']' << endl
         << "rating: " << fixed << setprecision(DIGIT_NUM) << ceil(getRating() * 10) / 10 << endl;
    return info.str();
}
string Recipe::getInfoInlineForChef() const
{
    ostringstream line;
    line << id << ' ' << title << ' ' << VEGETERIAN_POS[isVegeterian] << ' ' << minutes_to_ready << ' ' << fixed
         << setprecision(DIGIT_NUM) << ceil(getRating() * 10) / 10 << "\n";
    return line.str();
}
string Recipe::getInfoInline(vector<shared_ptr<Filter>> filters) const
{
    for (int i = 0; i < filters.size(); i++)
        if (!filters[i]->isPassFromFilter(tags, isVegeterian, minutes_to_ready, getRating())) return "";
    ostringstream line;
    line << id << ' ' << title << ' ' << VEGETERIAN_POS[isVegeterian] << ' ' << minutes_to_ready;
    return line.str();
}
void Recipe::addNewRating(double score, shared_ptr<Member> newRecorder)
{
    for (int i = 0; i < ratings.size(); i++)
        if (ratings[i]->recorder == newRecorder) throw BadRequest();
    checkScoreDomain(score);
    ratings.push_back(make_shared<Rating>(score, newRecorder, chef, shared_from_this()));
}
double Recipe::getRating() const
{
    double sum = 0, ratingsSize = 0;
    for (int i = 0; i < ratings.size(); i++)
    {
        if (ratings[i]->score != NOT_RATING) ratingsSize++;
        sum += ratings[i]->score;
    }
    return (ratingsSize == NOT_RATING) ? NOT_RATING : sum / ratingsSize;
    return 0;
}
void Recipe::changeScore(double score, shared_ptr<Member> newRecorder)
{
    int ratingIndex = searchRatingByUser(newRecorder, ratings);
    checkScoreDomain(score);
    ratings[ratingIndex]->score = score;
}
vector<string> Recipe::getIngredients() const { return ingredients; }
shared_ptr<Member> Recipe::getChef() const { return chef; }
bool Recipe::operator==(int id_) const { return (id == id_) ? true : false; }

void Recipe::initiation(int id_, string title_, vector<string> ingredients_, bool isVegeterian_, int minutes_to_ready_
, vector<string> tags_, string imageAddress_, shared_ptr<Member> chef_)
{
    id = id_;
    title = title_;
    ingredients = ingredients_;
    isVegeterian = isVegeterian_;
    minutes_to_ready = minutes_to_ready_;
    tags = tags_;
    imageAddress = imageAddress_;
    chef = chef_;
}
void Recipe::checkScoreDomain(double score) const { if (score > MAX_SCORE || score < MIN_SCORE) throw BadRequest(); }
bool operator==(int id_, const Recipe &recipe_) { return (recipe_.id == id_) ? true : false; }
bool operator==(int id_, shared_ptr<Recipe> recipe_) { return (recipe_->id == id_) ? true : false; }
bool operator==(shared_ptr<Recipe> recipe_, int id_) { return (recipe_->id == id_) ? true : false; }