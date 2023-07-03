#ifndef _MyServer_HPP_
#define _MyServer_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
#include "../../server/server.hpp"
class MyServer : public Server {
public:
  MyServer(int port = PORT);
};
#endif