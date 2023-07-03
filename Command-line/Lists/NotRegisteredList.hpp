#ifndef _NotRegistered_HPP_
#define _NotRegistered_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
#include "../MainObjects/ControlRoom.hpp"
#include "CommadsList.hpp"
const std::unordered_map<int, funcPtr> notRegisteredFuncs_ = {
    {SIGNUP, &ControlRoom::signup},
    {LOGIN, &ControlRoom::login},
    {SIGNUP_SUPPLIER, &ControlRoom::signupSupplier},
    {SUPPLIER_LOGIN, &ControlRoom::supplierLogin},
};
#endif