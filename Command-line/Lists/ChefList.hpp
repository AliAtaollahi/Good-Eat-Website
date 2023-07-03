#ifndef _ChefList_HPP_
#define _ChefList_HPP_
#include "../MainObjects/ControlRoom.hpp"
#include "CommadsList.hpp"
const std::unordered_map<int, funcPtr> chefFuncs_ = {
    {LOGOUT, &ControlRoom::logout},
    {POST_RECIPES, &ControlRoom::postRecipes},
    {GET_MY_RECIPES, &ControlRoom::getMyRecipes},
    {DELETE_RECIPES, &ControlRoom::deleteRecipes},
};
#endif