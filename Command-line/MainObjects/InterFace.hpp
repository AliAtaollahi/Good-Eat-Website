#ifndef _Interface_HPP_
#define _Interface_HPP_
#include "../MainObjects/ControlRoom.hpp"
class Interface
{
public:
    Interface() = default;
    void startProgram();

private:
    ControlRoom cr;
    std::vector<std::string> arguments;
    int getCommand(const std::vector<std::vector<std::string>> &cmds);
    bool isCommandEqual(const std::vector<std::string> &command_);
    void checkInmain(const std::vector<std::string> &command_, bool &isInMainBegin, bool &inMain);
    int getCommands();
    bool isOkayYesOrNo(std::string cmd) const;
};
#endif