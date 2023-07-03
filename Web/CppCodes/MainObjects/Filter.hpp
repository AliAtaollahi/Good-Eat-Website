#ifndef _Filter_HPP_
#define _Filter_HPP_
#include "../Errors/AllErrors.hpp"
class Filter
{
public:
    Filter() = default ;
    virtual bool isPassFromFilter(const std::vector<std::string> &tags, bool isVegeterian, int minutes_to_ready
    , double rating) = 0;
    virtual void update(std::string tagFilter_);
    virtual void update(std::pair<int, int> minutesToReadyFilter_, std::string str,std::string str_);
    virtual void update(std::pair<double, double> ratingFilter_, bool isDouble);
    virtual void update();
    virtual void clearFilter() = 0;
};
#endif