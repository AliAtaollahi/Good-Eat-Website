#include "MainObjects/InterFace.hpp"
using namespace std;
ControlRoom::ControlRoom() {
  allFilters.push_back(make_shared<TagFilter>());
  allFilters.push_back(make_shared<RateFilter>());
  allFilters.push_back(make_shared<TimeFilter>());
  allFilters.push_back(make_shared<VegeterianFilter>());
  lastRecipeId = 0;
  lastShelveId = 0;
}
Interface::Interface() { cr = make_shared<ControlRoom>(); }
void Interface::startProgram(int argc, char **argv) {
  while (1) {
    MyServer server(argc > 1 ? atoi(argv[1]) : 5000);
    try {
      serverPages(server);
      serverCss(server);
      serverJS(server);
      serverHandlers(server);
      serverImages(server);
      server.setNotFoundErrPage("static/404.html");
      server.run();
    }
    catch (Error &e) {
      e.printErrors();
    }
  }
}