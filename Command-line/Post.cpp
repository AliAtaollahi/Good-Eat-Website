#include "MainObjects/ControlRoom.hpp"
using namespace std;
void ControlRoom::login()
{
    int enteredIndex = search(arguments[USERNAME], allMembers, NotFound());
    if (allMembers[enteredIndex]->getPassword() != arguments[PASSWORD]) throw BadRequest();
    enteredMember = allMembers[enteredIndex];
}
void ControlRoom::logout()
{
    enteredMember = NULL;
    deleteFilters();
}
void ControlRoom::postRates()
{
    int recipeId = stod(arguments[ID_1]);
    int recipeIndex = search(recipeId, allRecipes, NotFound());
    allRecipes[recipeIndex]->addNewRating(stod(arguments[POST_RATE]), enteredMember);
}
void ControlRoom::postShelves()
{
    shared_ptr<Shelve> newShelve = make_shared<Shelve>(lastShelveId + 1, arguments[NAME], enteredMember);
    lastShelveId++;
    enteredMember->addShelve(newShelve);
    allShelves.push_back(newShelve);
    throw Message(to_string(lastShelveId) + "\n");
}
void ControlRoom::postFiltersPos1() { allFilters[TAG_FILTER]->update(arguments[FILTER_TAG]); }
void ControlRoom::postFiltersPos2() { allFilters[VEGETERIAN_POS_FILTER]->update(); }
void ControlRoom::postFiltersPos3() 
{ 
    allFilters[MIN_FILTER]->update({stod(arguments[FILTER_MIN_1]), stod(arguments[FILTER_MIN_2])}, " "," "); 
}
void ControlRoom::postFiltersPos4() 
{ 
    allFilters[RATE_FILTER]->update({stod(arguments[FILTER_RATE_1]), stod(arguments[FILTER_RATE_2])}, true); 
}
void ControlRoom::postRecipes()
{
    shared_ptr<Recipe> recipe = make_shared<Recipe>(lastRecipeId + 1, arguments, enteredMember);
    lastRecipeId++;
    enteredMember->addRecipes(recipe);
    allRecipes.push_back(recipe);
    throw Message(to_string(lastRecipeId) + "\n");
}
void ControlRoom::signup()
{
    string username = arguments[USERNAME], password = arguments[PASSWORD], type = arguments[TYPE];
    int type_ = search(type, MEMBERS, BadRequest());
    int userIndex = search(username, allMembers, Error());
    if (userIndex != NOT_FOUND) throw BadRequest();
    if (type_ == CHEF) allMembers.push_back(make_shared<Chef>(username, password));
    else if (type_ == USER) allMembers.push_back(make_shared<User>(username, password));
    enteredMember = allMembers.back();
}
void ControlRoom::signupSupplier()
{
    string username = arguments[USERNAME], email = arguments[EMAIL_SIGNUP], password = arguments[SUPPLIER_PASSWORD];
    int userIndex = search(username, allMembers, Error());
    int emailIndex = searchInEmails(email, allMembers);
    if (userIndex != NOT_FOUND || emailIndex != NOT_FOUND) throw BadRequest();
    allMembers.push_back(make_shared<Supplier>(username, email, password));
    enteredMember = allMembers.back();
}
void ControlRoom::supplierLogin()
{
    string email = arguments[EMAIL_LOGIN], password = arguments[PASSWORD];
    int emailIndex = searchInEmails(email, allMembers);
    if (emailIndex == NOT_FOUND || allMembers[emailIndex]->getPassword() != password) throw BadRequest();
    enteredMember = allMembers[emailIndex];
}
void ControlRoom::postOffers()
{
    int ingredientIndex = search(arguments[INGREDIENTS_POST], allIngredients, Error());
    if (ingredientIndex == NOT_FOUND)
    {
        allIngredients.push_back(make_shared<Ingredient>(arguments[INGREDIENTS_POST]));
        ingredientIndex = allIngredients.size() - 1;
    }
    int count = stod(arguments[COUNT]);
    double price = stod(arguments[PRICE]), packaging = stod(arguments[PACKAGING]);
    enteredMember->addOffer(count, price, packaging, allIngredients[ingredientIndex], enteredMember);
}
void ControlRoom::postOrders()
{
    int recipeIndex = search(stod(arguments[ID_1]), allRecipes, NotFound());
    buildOrder(recipeIndex);
    allOrders.back()->print();
    throw Message("");
}