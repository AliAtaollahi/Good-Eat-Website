#include "MainObjects/Order.hpp"
#include "Operators/OfferOperators.hpp"
using namespace std;
Order::Order(vector<shared_ptr<Offer>> offers_, shared_ptr<Recipe> recipe_, shared_ptr<Member> user_)
    : offers(offers_), recipe(recipe_), user(user_) { totalPrice = getTotalPrice(); }
void Order::print()
{
    vector<string> offerLines = collectIngredients();
    sort(offerLines.begin(), offerLines.end());
    cout << offerLines + "\n" << endl
         << fixed << setprecision(DIGIT_NUM_TOTAL_COST) << totalPrice << endl;
}
int Order::getRecipeId() { return recipe->getId(); }
shared_ptr<Member> Order::getUser() { return user; }
vector<string> Order::collectIngredients()
{
    vector<string> collection;
    vector<shared_ptr<Offer>> offers_ = offers;
    while (!offers_.empty())
    {
        vector<string> ingredients;
        string supplierUsername = offers_[0]->getSupplierUsername();
        for (int i = 0; i < offers_.size(); i++)
            if (supplierUsername == offers_[i]->getSupplierUsername()) 
                ingredients.push_back(offers_[i]->getIngredient());
        int i = 0;
        while (i < offers_.size())
            if (supplierUsername == offers_[i]->getSupplierUsername()) offers_.erase(offers_.begin() + i);
            else i++;
        collection.push_back(makeCollection(ingredients, supplierUsername));
    }
    return collection;
}
string Order::makeCollection(vector<string> ingredients, string username)
{
    sort(ingredients.begin(), ingredients.end());
    ostringstream out;
    out << username << " ";
    for (int i = 0; i < ingredients.size(); i++)
        if (i < ingredients.size() - 1) out << ingredients[i] << " ";
        else out << ingredients[i];
    return out.str();
}
double Order::getTotalPrice()
{
    double total = 0;
    for (int i = 0; i < offers.size(); i++) total += offers[i]->getBill();
    return floor(total);
}