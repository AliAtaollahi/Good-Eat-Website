#ifndef _Error_HPP_
#define _Error_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
class Error
{
public:
    Error() = default;
    Error(std::string errorText_);
    std::string getText() const;
    void printErrors() const;

protected:
    std::string errorText;
};
#endif