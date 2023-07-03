#include "MainObjects/Offer.hpp"
using namespace std;
Offer::Offer(int count_, double price_, double packaging_, shared_ptr<Ingredient> ingredient_, shared_ptr<Member> supplier_)
    : count(count_), price(price_), packaging(packaging_), ingredient(ingredient_), supplier(supplier_)
    , discount(NO_DISCOUNT) {}
int Offer::getCount() { return count; }
double Offer::getBill() { return discount * (price + packaging); }
void Offer::update(int count_, double price_)
{
    count = count_;
    price = price_;
}
string Offer::getSupplierUsername() { return supplier->getUsername(); }
string Offer::getIngredient() { return ingredient->name; }
void Offer::extract()
{
    if (count > NO_MATERIAL)
        count--;
}
void Offer::changeDiscount(double discount_) { discount = discount_; }
void Offer::gainSupplier() { supplier->gainCredits(getBill()); }
bool Offer::operator==(string name_) const { return (name_ == ingredient->name) ? true : false; }
bool operator==(string name_, const Offer &offer) { return (name_ == offer.ingredient->name) ? true : false; }
bool operator==(string name_, shared_ptr<Offer> offer) { return (name_ == offer->ingredient->name) ? true : false; }
bool operator==(shared_ptr<Offer> offer, string name_) { return (name_ == offer->ingredient->name) ? true : false; }
bool operator==(shared_ptr<Offer> offer, shared_ptr<Offer> offer_) { return (offer_->ingredient->name == offer->ingredient->name) ? true : false; }