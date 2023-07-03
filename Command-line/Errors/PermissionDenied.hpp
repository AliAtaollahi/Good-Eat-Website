#ifndef _PermissionDenied_HPP_
#define _PermissionDenied_HPP_
#include "../MainObjects/Error.hpp"
class PermissionDenied : public Error
{
public:
    PermissionDenied();
};
#endif