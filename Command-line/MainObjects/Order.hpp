#ifndef _ORDER_HPP
#define _ORDER_HPP
#include "../SideFuncs/AllFuncs.hpp"
#include "Offer.hpp"
#include "../Operators/OfferOperators.hpp"
class Order
{
public:
    Order(std::vector<std::shared_ptr<Offer>> offers_, std::shared_ptr<Recipe> recipe_, std::shared_ptr<Member> user_);

    void print();
    int getRecipeId();
    std::shared_ptr<Member> getUser();

private:
    std::vector<std::string> collectIngredients();
    std::string makeCollection(std::vector<std::string> ingredients, std::string username);
    double getTotalPrice();
    std::vector<std::shared_ptr<Offer>> offers;
    std::shared_ptr<Member> user;
    std::vector<bool> hasDiscount;
    std::shared_ptr<Recipe> recipe;
    double totalPrice;
};
#endif