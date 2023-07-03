#ifndef _User_HPP_
#define _User_HPP_
#include "../MainObjects/Member.hpp"
class User : public Member
{
public:
    User(std::string username_, std::string password_);
    void addShelve(std::shared_ptr<Shelve> newShelve);
    void deleteRecipeInShelves(std::shared_ptr<Recipe> recipe);

private:
    std::vector<std::shared_ptr<Shelve>> ownShelves;
};
#endif