#include "Errors/AllErrors.hpp"
#include "MainObjects/Member.hpp"
using namespace std;
Member::Member(string username_, string password_)
    : username(username_), password(password_) , credits(NO_MONEY) {}
string Member::getUsername() const { return username; }
string Member::getPassword() const { return password; }
void Member::addRecipes(shared_ptr<Recipe> recipe) {}
double Member::getRating(const vector<shared_ptr<Recipe>> &allRecipes) const { return 0; }
void Member::print(const vector<shared_ptr<Recipe>> &allRecipes) const {}
void Member::deleteRecipeById(int id) {}
void Member::addShelve(shared_ptr<Shelve> newShelve) {}
void Member::deleteRecipeInShelves(shared_ptr<Recipe> recipe) {}
bool Member::operator==(int type_) const { return (type == type_) ? true : false; }
bool Member::operator==(string username_) const { return (username == username_) ? true : false; }
double Member::getCredits() const { return credits; }
void Member::gainCredits(double credits_) { credits += credits_; }
void Member::changeCredet(double credits_) { credits = credits_; }
vector<shared_ptr<Offer>> Member::askOffers(std::vector<std::string> ingredient) { return {nullptr}; }
string Member::getEmail() { return ""; }
void Member::addOffer(int count_, double price_, double packaging_, shared_ptr<Ingredient> ingredient_
, shared_ptr<Member> supplier_) {}
void Member::updateOffer(int count_, double price_, shared_ptr<Ingredient> ingredient_) {}
void Member::deleteOffer(shared_ptr<Ingredient> ingredient_) {}
bool operator==(int type_, shared_ptr<Member> member) { return (member->type == type_) ? true : false; }
bool operator==(shared_ptr<Member> member, int type_) { return (member->type == type_) ? true : false; }
bool operator==(string username_, const Member &member) { return (member.username == username_) ? true : false; }
bool operator==(string username_, shared_ptr<Member> member) { return (member->username == username_) ? true : false; }
bool operator==(shared_ptr<Member> member, string username_) { return (member->username == username_) ? true : false; }