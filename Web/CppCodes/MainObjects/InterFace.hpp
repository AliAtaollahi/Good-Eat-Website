#ifndef _Interface_HPP_
#define _Interface_HPP_
#include "myServer.hpp"
#include "ControlRoom.hpp"
class Interface {
public:
  Interface();
  void startProgram(int argc, char **argv);

private:
  std::shared_ptr<ControlRoom> cr;
  void serverPages(MyServer &server);
  void serverCss(MyServer &server);
  void serverJS(MyServer &server);
  void serverHandlers(MyServer &server);
  void serverImages(MyServer &server);
  class LoginPageHandler : public RequestHandler {
  public:
    LoginPageHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class LoginHandler : public RequestHandler {
  public:
    LoginHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class SignupPageHandler : public RequestHandler {
  public:
    Response *callback(Request *req);
  };
  class SignupHandler : public RequestHandler {
  public:
    SignupHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class CreateRecipePageHandler : public RequestHandler {
  public:
    Response *callback(Request *req);
  };
  class PostRecipeHandler : public RequestHandler {
  public:
    PostRecipeHandler(std::shared_ptr<ControlRoom> cr_, MyServer *server_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
    MyServer *server;
  };
  class DeleteRecipeHandler : public RequestHandler {
  public:
    DeleteRecipeHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class homeChefHandler : public RequestHandler {
  public:
    homeChefHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class homeUserHandler : public RequestHandler {
  public:
    homeUserHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class ShowRecipeFormHandler : public RequestHandler {
  public:
    ShowRecipeFormHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class myShelvesHandler : public RequestHandler {
  public:
    myShelvesHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class ShelveRecipes : public RequestHandler {
  public:
    ShelveRecipes(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };

  class RecipeFormPageHandler : public RequestHandler {
  public:
    RecipeFormPageHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class RatingHandler : public RequestHandler {
  public:
    RatingHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class PutRecipeInShelveHandler : public RequestHandler {
  public:
    PutRecipeInShelveHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class AddShelfHandler : public RequestHandler {
  public:
    AddShelfHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class FiltersPage : public RequestHandler {
  public:
    Response *callback(Request *req);
  };
  class FiltersHandler : public RequestHandler {
  public:
    FiltersHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
  class DeleteFiltersHandler : public RequestHandler {
  public:
    DeleteFiltersHandler(std::shared_ptr<ControlRoom> cr_);
    Response *callback(Request *req);

  private:
    std::shared_ptr<ControlRoom> cr;
  };
};
void addSortShelf(std::vector<std::shared_ptr<Shelve>> &shelves, std::shared_ptr<Shelve> newShelf);
#endif