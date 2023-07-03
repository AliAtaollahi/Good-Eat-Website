#ifndef _SUPPLIER_HPP_
#define _SUPPLIER_HPP_
#include "../MainObjects/Member.hpp"
#include "../MainObjects/Offer.hpp"
class Supplier : public Member, public std::enable_shared_from_this<Supplier>
{
public:
    Supplier(std::string username_, std::string email_, std::string password_);
    std::string getEmail();
    void addOffer(int count_, double price_, double packaging_, std::shared_ptr<Ingredient> ingredient_
    , std::shared_ptr<Member> supplier_);
    void updateOffer(int count_, double price_, std::shared_ptr<Ingredient> ingredient_);
    void deleteOffer(std::shared_ptr<Ingredient> ingredient_);
    std::vector<std::shared_ptr<Offer>> askOffers(std::vector<std::string> ingredients);

private:
    std::string email;
    std::vector<std::shared_ptr<Offer>> allOffers;
};
#endif