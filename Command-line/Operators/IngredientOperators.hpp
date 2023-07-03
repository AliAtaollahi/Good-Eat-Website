#ifndef _INGREDIENT_OPERATORS_HPP_
#define _INGREDIENT_OPERATORS_HPP_
bool operator==(std::string name_, const Ingredient &ingredient);
bool operator==(std::string name_, std::shared_ptr<Ingredient> ingredient);
bool operator==(std::shared_ptr<Ingredient> ingredient, std::string name_);
#endif