#ifndef _UserList_HPP_
#define _UserList_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
#include "../MainObjects/ControlRoom.hpp"
#include "CommadsList.hpp"
const std::unordered_map<int, funcPtr> userFuncs_ = {
    {LOGOUT, &ControlRoom::logout},
    {POST_RATES, &ControlRoom::postRates},
    {POST_SHELVES, &ControlRoom::postShelves},
    {POST_FILTERS_POS_1, &ControlRoom::postFiltersPos1},
    {POST_FILTERS_POS_2, &ControlRoom::postFiltersPos2},
    {POST_FILTERS_POS_3, &ControlRoom::postFiltersPos3},
    {POST_FILTERS_POS_4, &ControlRoom::postFiltersPos4},
    {GET_RECIPES_POS_1, &ControlRoom::getRecipesPos1},
    {GET_RECIPES_POS_2, &ControlRoom::getRecipesPos2},
    {GET_SHELVES, &ControlRoom::getShelves},
    {GET_SHELVES_RECIPES, &ControlRoom::getShelvesRecipes},
    {GET_CHEFS_POS_1, &ControlRoom::getChefsPos1},
    {GET_CHEFS_POS_2, &ControlRoom::getChefsPos2},
    {GET_USERS, &ControlRoom::getUsers},
    {PUT_RATES, &ControlRoom::putRates},
    {PUT_SHELVES_RECIPES, &ControlRoom::putShelvesRecipes},
    {DELETE_FILTERS, &ControlRoom::deleteFilters},
    {DELETE_SHELVES_RECIPES, &ControlRoom::deleteShelvesRecipes},
    {GET_CREDITS, &ControlRoom::getCredits},
    {PUT_CREDITS, &ControlRoom::putCredits},
    {POST_ORDERS, &ControlRoom::postOrders},
    {GET_ORDERS, &ControlRoom::getOrders},
};
#endif