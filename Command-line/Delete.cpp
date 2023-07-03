#include "MainObjects/ControlRoom.hpp"
using namespace std;
void ControlRoom::deleteRecipes()
{
    int recipeIndex = search(stod(arguments[ID_1]), allRecipes, NotFound());
    if (allRecipes[recipeIndex]->getChef() != enteredMember) throw PermissionDenied();
    enteredMember->deleteRecipeById(allRecipes[recipeIndex]->getId());
    allRecipes.erase(allRecipes.begin() + recipeIndex);
}
void ControlRoom::deleteFilters()
{
    for (int i = 0; i < allFilters.size(); i++)
        allFilters[i]->clearFilter();
}
void ControlRoom::deleteShelvesRecipes()
{
    int shelfId = stod(arguments[ID_1]), recipeId = stod(arguments[ID_2]);
    int shelfIndex = search(shelfId, allShelves, NotFound());
    if (allShelves[shelfIndex]->getOwner() != enteredMember) throw PermissionDenied();
    allShelves[shelfIndex]->deleteRecipe(recipeId);
}
void ControlRoom::deleteOffers()
{
    int ingredientIndex = search(arguments[INGREDIENTS_POST], allIngredients, BadRequest());
    enteredMember->deleteOffer(allIngredients[ingredientIndex]);
}