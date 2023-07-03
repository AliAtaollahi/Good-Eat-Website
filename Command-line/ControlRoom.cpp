#include "MainObjects/ControlRoom.hpp"
#include "Lists/AllLists.hpp"
using namespace std;
ControlRoom::ControlRoom()
{
    enteredMember = NULL;
    allFilters.push_back(make_shared<TagFilter>());
    allFilters.push_back(make_shared<RateFilter>());
    allFilters.push_back(make_shared<TimeFilter>());
    allFilters.push_back(make_shared<VegeterianFilter>());
    lastRecipeId = 0;
    lastShelveId = 0;
}
void ControlRoom::mainMenu(int cmd, const vector<string> arguments_)
{
    arguments = arguments_;
    if (!enteredMember) routeCommand(cmd, notRegisteredFuncs_);
    else if (enteredMember == USER) routeCommand(cmd, userFuncs_);
    else if (enteredMember == CHEF) routeCommand(cmd, chefFuncs_);
    else if (enteredMember == SUPPLIER) routeCommand(cmd, supplierFuncs_);
}

void ControlRoom::routeCommand(int cmd, const unordered_map<int, funcPtr> &list)
{
    auto func = list.find(cmd);
    if (func == list.end()) throw PermissionDenied();
    (this->*(func->second))();
}
void ControlRoom::buildOrder(int recipeIndex)
{
    vector<string> ingredients = allRecipes[recipeIndex]->getIngredients();
    vector<shared_ptr<Offer>> offers, bestOffers;
    counts.clear();
    for (int i = 0; i < allMembers.size(); i++)
    {
        if (!(allMembers[i] == SUPPLIER)) continue;
        offers = allMembers[i]->askOffers(ingredients);
        addOfferToBest(offers, bestOffers);
    }
    if (ingredients.size() != bestOffers.size()) throw NotFound();
    addDiscout(bestOffers);
    exchange(bestOffers);
    allOrders.push_back(make_shared<Order>(bestOffers, allRecipes[recipeIndex], enteredMember));
}
void ControlRoom::addOfferToBest(const vector<shared_ptr<Offer>> &offers, vector<shared_ptr<Offer>> &bestOffers)
{
    for (int i = 0; i < offers.size(); i++)
    {
        int offerIndex = search(offers[i], bestOffers, Error());
        if (offerIndex == NOT_FOUND)
        {
            bestOffers.push_back(offers[i]);
            counts.push_back(offers[i]->getCount());
        }
        else
        {
            counts[offerIndex] += offers[i]->getCount();
            if (offers[i]->getBill() < bestOffers[offerIndex]->getBill()) bestOffers[offerIndex] = offers[i];
        }
    }
}
void ControlRoom::addDiscout(const vector<shared_ptr<Offer>> &bestOffers)
{
    for (int i = 0; i < bestOffers.size(); i++)
        if (counts[i] >= COUNT_FOR_DISCOUNT) bestOffers[i]->changeDiscount(DISCOUNT);
        else bestOffers[i]->changeDiscount(NO_DISCOUNT);
}
void ControlRoom::exchange(const vector<shared_ptr<Offer>> &offers)
{
    vector<bool> hasDiscount;
    double userWallet = enteredMember->getCredits();
    for (int i = 0; i < offers.size(); i++)
        userWallet += (-1) * offers[i]->getBill();
    if (userWallet < NO_MONEY) throw BadRequest();
    enteredMember->changeCredet(userWallet);
    for (int i = 0; i < offers.size(); i++)
    {
        offers[i]->extract();
        offers[i]->gainSupplier();
    }
}