#ifndef _Recipe_HPP_
#define _Recipe_HPP_
#include "../SideFuncs/AllFuncs.hpp"
#include "../Operators/RecipeOperators.hpp"
#include "Rating.hpp"
#include "../Filters/AllFilters.hpp"
class Recipe : public std::enable_shared_from_this<Recipe>
{
public:
    Recipe() = default;
    Recipe(int id_, std::string title_, std::vector<std::string> ingredients_, bool isVegeterian_, int minutes_to_ready_
    , std::vector<std::string> tags_, std::string imageAddress_, std::shared_ptr<Member> chef_);
    Recipe(int id_, const std::vector<std::string> arguments, std::shared_ptr<Member> chef_);
    std::string getTitle() const;
    int getId() const;
    std::string getInfo() const;
    std::string getInfoInlineForChef() const;
    std::string getInfoInline(std::vector<std::shared_ptr<Filter>> filters) const;
    void addNewRating(double score, std::shared_ptr<Member> newRecorder);
    double getRating() const;
    void changeScore(double score, std::shared_ptr<Member> newRecorder);
    std::shared_ptr<Member> getChef() const;
    std::vector<std::string> getIngredients() const;
    bool operator==(int id_) const;
    friend bool operator==(int id_, const Recipe &recipe_);
    friend bool operator==(int id_, std::shared_ptr<Recipe> recipe_);
    friend bool operator==(std::shared_ptr<Recipe> recipe_, int id_);

private:
    void initiation(int id_, std::string title_, std::vector<std::string> ingredients_, bool isVegeterian_
    , int minutes_to_ready_, std::vector<std::string> tags_, std::string imageAddress_, std::shared_ptr<Member> chef_);
    void checkScoreDomain(double score) const;
    int id;
    std::string title;
    std::vector<std::string> ingredients;
    bool isVegeterian;
    int minutes_to_ready;
    std::vector<std::string> tags;
    std::string imageAddress;
    double rating;
    std::vector<std::shared_ptr<Rating>> ratings;
    std::shared_ptr<Member> chef;
};
#endif