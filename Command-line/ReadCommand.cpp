#include "MainObjects/InterFace.hpp"
#include "Lists/CommadsList.hpp"
using namespace std;
void Interface::startProgram()
{
    while (getCommands())
    {
        try
        {
            int cmd = getCommand(CMDS);
            cr.mainMenu(cmd, arguments);
            cout << "OK" << endl;
        } catch (Error &e) {
            e.printErrors();
        } catch (Message &m) {
            m.printMessage();
        }
    }
}