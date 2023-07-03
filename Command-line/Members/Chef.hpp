#ifndef _Chef_HPP_
#define _Chef_HPP_
#include "../MainObjects/Member.hpp"
class Chef : public Member , public std::enable_shared_from_this<Chef>
{
public:
    Chef(std::string username_, std::string password_);
    void addRecipes(std::shared_ptr<Recipe> recipe);
    double getRating(const std::vector<std::shared_ptr<Recipe>> &allRecipes) const;
    void print(const std::vector<std::shared_ptr<Recipe>> &allRecipes) const;
    void deleteRecipeById(int id);

private:
    std::vector<std::shared_ptr<Recipe>> madeRecipes;
};
#endif