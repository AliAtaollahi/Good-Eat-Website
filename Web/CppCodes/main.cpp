#include "../server/server.hpp"
#include "MainObjects/InterFace.hpp"
using namespace std;
int main(int argc, char **argv) {
  srand(time(NULL));
  Interface interface;
  interface.startProgram(argc, argv);
  return 0;
}