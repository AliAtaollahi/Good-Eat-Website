#include "Errors/AllErrors.hpp"
#include "MainObjects/Member.hpp"
using namespace std;
Member::Member(string username_, string password_)
    : username(username_), password(password_) {}
string Member::getUsername() const { return username; }
string Member::getPassword() const { return password; }
void Member::addRecipes(shared_ptr<Recipe> recipe) {}
string Member::getEmail() { return ""; }
double Member::getRating(const vector<shared_ptr<Recipe>> &allRecipes) const { return 0; }
void Member::deleteRecipeById(int id) {}
void Member::addShelve(shared_ptr<Shelve> newShelve) {}
void Member::deleteRecipeInShelves(shared_ptr<Recipe> recipe) {}
bool Member::operator==(int type_) const { return (type == type_) ? true : false; }
bool Member::operator==(string username_) const { return (username == username_) ? true : false; }
bool operator==(int type_, shared_ptr<Member> member) { return (member->type == type_) ? true : false; }
bool operator==(shared_ptr<Member> member, int type_) { return (member->type == type_) ? true : false; }
bool operator==(string username_, const Member &member) { return (member.username == username_) ? true : false; }
bool operator==(string username_, shared_ptr<Member> member) { return (member->username == username_) ? true : false; }
bool operator==(shared_ptr<Member> member, string username_) { return (member->username == username_) ? true : false; }