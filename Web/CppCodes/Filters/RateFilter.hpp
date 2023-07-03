#ifndef _RateFilter_HPP_
#define _RateFilter_HPP_
class RateFilter : public Filter
{
public:
    RateFilter();
    void update(std::pair<double, double> ratingFilter_, bool isDouble);
    void clearFilter();
    bool isPassFromFilter(const std::vector<std::string> &tags, bool isVegeterian, int minutes_to_ready, double rating);

private:
    std::pair<double, double> ratingFilter;
};
#endif