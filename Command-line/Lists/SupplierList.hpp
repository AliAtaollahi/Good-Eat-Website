#ifndef _SupplierList_HPP_
#define _SupplierList_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
#include "../MainObjects/ControlRoom.hpp"
#include "CommadsList.hpp"
const std::unordered_map<int, funcPtr> supplierFuncs_ = {
    {LOGOUT, &ControlRoom::logout},
    {POST_OFFERS, &ControlRoom::postOffers},
    {PUT_OFFERS, &ControlRoom::putOffers},
    {DELETE_OFFERS, &ControlRoom::deleteOffers},
    {GET_CREDITS, &ControlRoom::getCredits},
};
#endif