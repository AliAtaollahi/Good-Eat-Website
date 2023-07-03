#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "MainObjects/Shelve.hpp"
using namespace std;
Supplier::Supplier(string username_, string email_, string password_)
    : Member(username_, password_), email(email_) { type = SUPPLIER; }
string Supplier::getEmail() { return email; }
void Supplier::addOffer(int count_, double price_, double packaging_, shared_ptr<Ingredient> ingredient_, shared_ptr<Member> supplier_)
{
    int offerIndex = search(ingredient_->name, allOffers, Error());
    if (offerIndex != NOT_FOUND) throw BadRequest();
    allOffers.push_back(make_shared<Offer>(count_, price_, packaging_, ingredient_, shared_from_this()));
}
void Supplier::updateOffer(int count_, double price_, shared_ptr<Ingredient> ingredient_)
{
    int offerIndex = search(ingredient_->name, allOffers, BadRequest());
    allOffers[offerIndex]->update(count_, price_);
}
void Supplier::deleteOffer(shared_ptr<Ingredient> ingredient_)
{
    int offerIndex = search(ingredient_->name, allOffers, BadRequest());
    allOffers.erase(allOffers.begin() + offerIndex);
}
vector<shared_ptr<Offer>> Supplier::askOffers(vector<string> ingredients)
{
    vector<shared_ptr<Offer>> offers;
    for (int i = 0; i < allOffers.size(); i++)
        for (int j = 0; j < ingredients.size(); j++)
            if (allOffers[i]->getCount() > NO_MATERIAL && allOffers[i] == ingredients[j])
                offers.push_back(allOffers[i]);
    return offers;
}
