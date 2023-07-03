#ifndef _INGREDIENT_OPERATORS_HPP_
#define _INGREDIENT_OPERATORS_HPP_
bool operator==(std::string name_, const Offer &offer);
bool operator==(std::string name_, std::shared_ptr<Offer> offer);
bool operator==(std::shared_ptr<Offer> offer, std::string name_);
bool operator==(std::shared_ptr<Offer> offer, std::shared_ptr<Offer> offer_);
#endif