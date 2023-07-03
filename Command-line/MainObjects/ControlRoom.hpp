#ifndef _ControlRoom_HPP_
#define _ControlRoom_HPP_
#include "../Errors/AllErrors.hpp"
#include "../Filters/AllFilters.hpp"
#include "../SideFuncs/AllFuncs.hpp"
#include "Rating.hpp"
#include "Recipe.hpp"
#include "Shelve.hpp"
#include "Offer.hpp"
#include "Order.hpp"
#include "../Members/AllMembers.hpp"
#include "../Operators/OtherOperators.hpp"
typedef void (ControlRoom::*funcPtr)();
class ControlRoom
{
public:
    ControlRoom();
    void mainMenu(int cmd, const std::vector<std::string> arguments_);
    void routeCommand(int cmd, const std::unordered_map<int, funcPtr> &list);
    void login();
    void logout();
    void postRates();
    void postShelves();
    void postFiltersPos1();
    void postFiltersPos2();
    void postFiltersPos3();
    void postFiltersPos4();
    void postRecipes();
    void signup();
    void getShelves();
    void getShelvesRecipes();
    void getMyRecipes();
    void getUsers();
    void getChefsPos1();
    void getChefsPos2();
    void getRecipesPos1();
    void getRecipesPos2();
    void putRates();
    void putShelvesRecipes();
    void deleteRecipes();
    void deleteFilters();
    void deleteShelvesRecipes();
    void signupSupplier();
    void supplierLogin();
    void postOffers();
    void putOffers();
    void deleteOffers();
    void getCredits();
    void putCredits();
    void postOrders();
    void getOrders();

private:
    std::vector<std::shared_ptr<Member>> allMembers;
    std::vector<std::shared_ptr<Recipe>> allRecipes;
    std::vector<std::shared_ptr<Shelve>> allShelves;
    std::vector<std::shared_ptr<Filter>> allFilters;
    std::vector<std::shared_ptr<Ingredient>> allIngredients;
    std::vector<std::shared_ptr<Order>> allOrders;
    std::vector<int> counts;
    std::vector<std::string> arguments;
    int lastRecipeId;
    int lastShelveId;
    std::shared_ptr<Member> enteredMember;
    void buildOrder(int recipeIndex);
    void addOfferToBest(const std::vector<std::shared_ptr<Offer>> &offers, std::vector<std::shared_ptr<Offer>> &bestOffers);
    void addDiscout(const std::vector<std::shared_ptr<Offer>> &bestOffers);
    void exchange(const std::vector<std::shared_ptr<Offer>> &offers);
};
#endif