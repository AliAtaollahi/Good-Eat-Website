#include "MainObjects/ControlRoom.hpp"
using namespace std;
void ControlRoom::getShelves()
{
    int userIndex = search(arguments[USERNAME], allMembers, NotFound());
    vector<string> shelves;
    for (int i = 0; i < allShelves.size(); i++)
        if (allShelves[i]->getOwner() == allMembers[userIndex])
            shelves.push_back(to_string(allShelves[i]->getId()) + " " + allShelves[i]->getName() + "\n");
    for (int i = 0; i < stod(arguments[LIMIT]) && i < shelves.size(); i++)
        cout << shelves[i];
    throw Message("");
}
void ControlRoom::getShelvesRecipes()
{
    int shelfIndex = search(stod(arguments[ID_1]), allShelves, NotFound());
    vector<string> recipes = allShelves[shelfIndex]->getRecipesInfo();
    recipes = sortByOrder(recipes, NAME_ORDER, ' ');
    if (recipes.empty()) throw Empty();
    cout << recipes + "\n" << endl;
    throw Message("");
}
void ControlRoom::getMyRecipes()
{
    vector<string> recipes;
    for (int i = 0; i < allRecipes.size(); i++)
        if (allRecipes[i]->getChef() == enteredMember) recipes.push_back(allRecipes[i]->getInfo());
    recipes = sortByOrder(recipes, NAME_ORDER, '\n');
    if (recipes.empty()) throw(Empty());
    cout << recipes + "\n" << endl;
    throw Message("");
}
void ControlRoom::getUsers()
{
    vector<string> usernames;
    for (int i = 0; i < allMembers.size(); i++)
        if (allMembers[i] != enteredMember && allMembers[i] == USER) usernames.push_back(allMembers[i]->getUsername());
    if (usernames.empty()) throw Empty();
    sort(usernames.begin(), usernames.end());
    cout << usernames + "\n" << endl;
    throw Message("");
}
void ControlRoom::getChefsPos1()
{
    vector<string> chefs;
    for (int i = 0; i < allMembers.size(); i++)
        if (allMembers[i] == CHEF)
        {
            ostringstream rating_;
            rating_ << fixed << setprecision(DIGIT_NUM) << ceil(allMembers[i]->getRating(allRecipes) * 10) / 10;
            string rating = rating_.str();
            chefs.push_back(allMembers[i]->getUsername() + " " + rating);
        }
    if (chefs.empty()) throw Empty();
    sort(chefs.begin(), chefs.end());
    cout << chefs + "\n" << endl;
    throw Message("");
}
void ControlRoom::getChefsPos2()
{
    int chefIndex = search(arguments[USERNAME], allMembers, NotFound());
    if (allMembers[chefIndex] == USER) throw NotFound();
    allMembers[chefIndex]->print(allRecipes);
    throw Message("");
}
void ControlRoom::getRecipesPos1()
{
    vector<string> recipes;
    string recipe;
    for (int i = 0; i < allRecipes.size(); i++)
    {
        if ((recipe = allRecipes[i]->getInfoInline(allFilters)) == "") continue;
        recipes.push_back(recipe);
    }
    recipes = sortByOrder(recipes, NAME_ORDER, ' ');
    if (recipes.empty()) throw Empty();
    cout << recipes + "\n" << endl;
    throw Message("");
}
void ControlRoom::getRecipesPos2()
{
    int wantedRecipeId = stod(arguments[ID_1]);
    int indexRecipe = search(wantedRecipeId, allRecipes, NotFound());
    cout << allRecipes[indexRecipe]->getInfo();
    throw Message("");
}
void ControlRoom::getOrders()
{
    int index = 1;
    bool isThereOrder = false;
    for (int i = 0; i < allOrders.size(); i++)
        if (allOrders[i]->getUser() == enteredMember)
        {
            isThereOrder = true;
            cout << "====order_" << index << "====" << endl << allOrders[i]->getRecipeId() << endl;
            allOrders[i]->print();
            index++;
        }
    throw Message("");
}
void ControlRoom::getCredits()
{
    cout << floor<int>(enteredMember->getCredits()) << endl;
    throw Message("");
}