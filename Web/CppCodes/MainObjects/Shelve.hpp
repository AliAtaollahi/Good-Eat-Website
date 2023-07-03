#ifndef _Shelve_HPP_
#define _Shelve_HPP_
#include "../SideFuncs/AllFuncs.hpp"
#include "../Members/AllMembers.hpp"
#include "../Operators/ShelveOperators.hpp"
class Shelve {
public:
  Shelve() = default;
  Shelve(int id_, std::string name_, std::shared_ptr<Member> owner_);
  int getId() const;
  std::string getName() const;
  std::shared_ptr<Member> getOwner() const;
  void addRecipe(std::shared_ptr<Recipe> newRecipe, std::shared_ptr<Member> member);
  std::string getRecipesInfo() const;
  std::string getRecipesForm(int shelfId);
  void deleteRecipe(int id);
  bool operator==(int id_) const;
  friend bool operator==(int id_, const Shelve &recipe_);
  friend bool operator==(int id_, std::shared_ptr<Shelve> recipe_);
  friend bool operator==(std::shared_ptr<Shelve> recipe_, int id_);

private:
  int id;
  std::string name;
  std::vector<std::shared_ptr<Recipe>> recipes;
  std::shared_ptr<Member> owner;
};
void addSortShelf(std::vector<std::shared_ptr<Shelve>> &shelves, std::shared_ptr<Shelve> newShelf);
#endif