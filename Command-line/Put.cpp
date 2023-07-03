#include "SideFuncs/AllFuncs.hpp"
#include "MainObjects/ControlRoom.hpp"
using namespace std;
void ControlRoom::putRates()
{
    int recipeId = stod(arguments[ID_1]);
    int recipeIndex = search(recipeId, allRecipes, NotFound());
    allRecipes[recipeIndex]->changeScore(stod(arguments[PUT_RATE]), enteredMember);
}
void ControlRoom::putShelvesRecipes()
{
    int shelfId = stod(arguments[ID_1]), recipeId = stod(arguments[ID_2]);
    int shelfIndex = search(shelfId, allShelves, NotFound());
    if (allShelves[shelfIndex]->getOwner() != enteredMember) throw PermissionDenied();
    int recipeIndex = search(recipeId, allRecipes, NotFound());
    allShelves[shelfIndex]->addRecipe(allRecipes[recipeIndex], enteredMember);
}
void ControlRoom::putOffers()
{
    int ingredientIndex = search(arguments[INGREDIENTS_POST], allIngredients, BadRequest());
    int count = stod(arguments[COUNT]);
    double price = stod(arguments[PRICE]);
    enteredMember->updateOffer(count, price, allIngredients[ingredientIndex]);
}
void ControlRoom::putCredits() { enteredMember->gainCredits(stod(arguments[MONEY])); }