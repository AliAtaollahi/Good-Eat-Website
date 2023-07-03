#ifndef _RecipeOperators_HPP_
#define _RecipeOperators_HPP_
bool operator==(int id_, const Recipe &recipe_);
bool operator==(int id_, std::shared_ptr<Recipe> recipe_);
bool operator==(std::shared_ptr<Recipe> recipe_, int id_);
#endif