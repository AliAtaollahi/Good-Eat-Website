#ifndef _Message_HPP_
#define _Message_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
class Message
{
public:
    Message(std::string text_);
    void printMessage() const;

private:
    std::string text;
};
#endif