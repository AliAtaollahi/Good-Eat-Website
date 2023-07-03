#ifndef _Rating_HPP_
#define _Rating_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
#include "../Members/Chef.hpp"
#include "../Members/User.hpp"
class Rating
{
public:
    Rating(double score_, std::shared_ptr<Member> recorder_, std::shared_ptr<Member> chef_, std::shared_ptr<Recipe> recipe_);
    double score;
    std::shared_ptr<Member> recorder;
    std::shared_ptr<Member> chef;
    std::shared_ptr<Recipe> recipe;
};
#endif