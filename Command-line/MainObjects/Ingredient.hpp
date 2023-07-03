#ifndef _INGREDIENT_HPP_
#define _INGREDIENT_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
#include "../Operators/IngredientOperators.hpp"
class Ingredient
{
public:
    Ingredient(std::string name_);
    bool operator==(std::string name_) const;
    friend bool operator==(std::string name_, const Ingredient &ingredient);
    friend bool operator==(std::string name_, std::shared_ptr<Ingredient> ingredient);
    friend bool operator==(std::shared_ptr<Ingredient> ingredient, std::string name_);
    std::string name;
};
#endif