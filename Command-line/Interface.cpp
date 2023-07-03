#include "MainObjects/InterFace.hpp"
#include "Lists/CommadsList.hpp"
using namespace std;
int Interface::getCommand(const vector<vector<string>> &cmds)
{
    int cmd = NOT_FOUND;
    bool isInMainBegin = false, inMain = true;
    for (int i = 0; i < cmds.size(); i++)
    {
        checkInmain(cmds[i], isInMainBegin, inMain);
        if (!isCommandEqual(cmds[i])) continue;
        return cmd = i + 1;
    }
    if (cmd == NOT_FOUND)
        if (isInMainBegin) throw NotFound();
        else throw BadRequest();
    return cmd;
}
bool Interface::isCommandEqual(const vector<string> &command_)
{
    bool check = true;
    if (command_.size() != arguments.size()) return false;
    for (int i = 0; i < command_.size(); i++)
    {
        if (command_[i] == NOT_MATTER) continue;
        if (command_[i] == MUST_BE_YES_OR_NO)
            if (isOkayYesOrNo(arguments[i])) continue;
            else return check = false;
        if (command_[i] == MUST_BE_NUM)
            if (isNumber(arguments[i]) && stod(arguments[i]) >= 0) continue;
            else return check = false;
        if (command_[i] == MUST_BE_INT)
            if (isNumber(arguments[i]) && stod(arguments[i]) >= 0 && stod(arguments[i]) - floor(stod(arguments[i])) == 0) continue;
            else return check = false;
        if (command_[i] != arguments[i]) return check = false;
    }
    return check;
}
void Interface::checkInmain(const vector<string> &command_, bool &isInMainBegin, bool &inMain)
{
    if (command_[MAIN_COMMAND] == arguments[MAIN_COMMAND])
        if (command_.size() >= 2 && command_[SUB_COMMAND] == arguments[SUB_COMMAND])
        {
            isInMainBegin = false;
            inMain = false;
        }
        else if (inMain) isInMainBegin = true;
}
int Interface::getCommands()
{
    string line;
    if (!getline(cin, line)) return END_PROGRAM;
    arguments = divideLine(line, ' ');
    return NOT_END_PROGRAM;
}
bool Interface::isOkayYesOrNo(string cmd) const { return (cmd == "No" || cmd == "Yes") ? true : false; }