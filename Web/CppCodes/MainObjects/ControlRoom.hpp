#ifndef _ControlRoom_HPP_
#define _ControlRoom_HPP_
#include "Shelve.hpp"
#include "myServer.hpp"
#include "../Errors/AllErrors.hpp"
#include "../Filters/AllFilters.hpp"
#include "../SideFuncs/AllFuncs.hpp"
#include "Rating.hpp"
#include "Recipe.hpp"
#include "../Members/AllMembers.hpp"
#include "../Operators/OtherOperators.hpp"
class ControlRoom {
public:
  ControlRoom();
  int login(std::string username, std::string password);
  void logout();
  void postRates(int sessionId, int id, std::string rating);
  void postShelves(int sessionId, std::string shelfName);
  void postFiltersPos1(std::string tags);
  void postFiltersPos2();
  void postFiltersPos3(std::string minTime, std::string maxTime);
  void postFiltersPos4(std::string minRate, std::string maxRate);
  void postRecipes(int sessionId, const std::vector<std::string> &arguments_);
  int signup(std::string username, std::string password, std::string type);
  std::string getShelves(int sessionId);
  std::string getShelvesRecipes(int shelfId);
  void putShelvesRecipes(int sessionId, int recipeId, std::string shelfId);
  void deleteRecipes(int sessionId, std::string id);
  void deleteFilters();
  void deleteShelvesRecipes(int recipeId, int shelfId);
  std::string getMyRecipes(int sessionId);
  std::string getAllRecipes();
  std::string getRecipeInfo(int id);
  std::string getShelfIntruduce(int shelfId);
  int getEnteredJob(int sessionId);

private:
  std::vector<std::shared_ptr<Member>> allMembers;
  std::vector<std::shared_ptr<Recipe>> allRecipes;
  std::vector<std::shared_ptr<Shelve>> allShelves;
  std::vector<std::shared_ptr<Filter>> allFilters;
  int lastRecipeId;
  int lastShelveId;
};
void addSortShelf(std::vector<std::shared_ptr<Shelve>> &shelves, std::shared_ptr<Shelve> newShelf);
#endif