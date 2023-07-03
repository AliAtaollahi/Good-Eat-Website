#include "MainObjects/Ingredient.hpp"
using namespace std;
Ingredient::Ingredient(string name_) : name(name_) {}
bool Ingredient::operator==(string name_) const { return (name_ == name) ? true : false; }
bool operator==(string name_, const Ingredient &ingredient) { return (name_ == ingredient.name) ? true : false; }
bool operator==(string name_, shared_ptr<Ingredient> ingredient) { return (name_ == ingredient->name) ? true : false; }
bool operator==(shared_ptr<Ingredient> ingredient, string name_) { return (name_ == ingredient->name) ? true : false; }