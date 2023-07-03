#ifndef _TagFilter_HPP_
#define _TagFilter_HPP_
class TagFilter : public Filter
{
public:
    TagFilter();
    void clearFilter();
    void update(std::string tagFilter_);
    bool isPassFromFilter(const std::vector<std::string> &tags, bool isVegeterian, int minutes_to_ready, double rating);
private:
    std::string tagFilter;
};
#endif