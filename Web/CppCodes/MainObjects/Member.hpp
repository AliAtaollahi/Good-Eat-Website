#ifndef _Member_HPP_
#define _Member_HPP_
#include "../Errors/AllErrors.hpp"
#include "../Operators/OtherOperators.hpp"
#include "../Operators/MemberOperators.hpp"
#include "../SideFuncs/AllFuncs.hpp"
class Member {
public:
  Member(std::string username_, std::string password_);
  std::string getUsername() const;
  std::string getPassword() const;
  virtual std::string getEmail();
  virtual void addRecipes(std::shared_ptr<Recipe> recipe);
  virtual double getRating(const std::vector<std::shared_ptr<Recipe>> &allRecipes) const;
  virtual void deleteRecipeById(int id);
  virtual void addShelve(std::shared_ptr<Shelve> newShelve);
  virtual void deleteRecipeInShelves(std::shared_ptr<Recipe> recipe);
  bool operator==(int type_) const;
  friend bool operator==(int type_, const Member &member);
  friend bool operator==(int type_, std::shared_ptr<Member> member);
  friend bool operator==(std::shared_ptr<Member> member, int type_);
  bool operator==(std::string username_) const;
  friend bool operator==(std::string username_, const Member &member);
  friend bool operator==(std::string username_, std::shared_ptr<Member> member);
  friend bool operator==(std::shared_ptr<Member> member, std::string username_);

protected:
  std::string username;
  std::string password;
  int type;
};
#endif