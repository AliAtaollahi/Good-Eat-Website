#ifndef _OFFER_HPP
#define _OFFER_HPP
#include "../SideFuncs/AllFuncs.hpp"
#include "Ingredient.hpp"
#include "Recipe.hpp"
#include "../Members/AllMembers.hpp"
#include "../Operators/OfferOperators.hpp"
class Offer
{
public:
    Offer(int count_, double price_, double packaging_, std::shared_ptr<Ingredient> ingredient_
    , std::shared_ptr<Member> supplier_);
    int getCount();
    double getBill();
    void update(int count_, double price_);
    std::string getSupplierUsername();
    std::string getIngredient();
    void extract();
    void changeDiscount(double discount_);
    void gainSupplier();
    bool operator==(std::string name_) const;
    friend bool operator==(std::string name_, const Offer &offer);
    friend bool operator==(std::string name_, std::shared_ptr<Offer> offer);
    friend bool operator==(std::shared_ptr<Offer> offer, std::string name_);
    friend bool operator==(std::shared_ptr<Offer> offer, std::shared_ptr<Offer> offer_);

private:
    int count;
    double price;
    double packaging;
    double discount;
    std::shared_ptr<Ingredient> ingredient;
    std::shared_ptr<Member> supplier;
};
#endif