#ifndef _VegetarianFilter_HPP_
#define _VegetarianFilter_HPP_
class VegeterianFilter : public Filter
{
public:
    VegeterianFilter();
    void update();
    void clearFilter();

private:
    int isVegeterianFilter;
    bool isPassFromFilter(const std::vector<std::string> &tags, bool isVegeterian, int minutes_to_ready, double rating);
};
#endif