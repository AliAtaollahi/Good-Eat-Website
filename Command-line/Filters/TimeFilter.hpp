#ifndef _TimeFilter_HPP_
#define _TimeFilter_HPP_
class TimeFilter : public Filter
{
public:
    TimeFilter();
    void update(std::pair<int, int> minutesToReadyFilter_, std::string str,std::string str_);
    void clearFilter();
    bool isPassFromFilter(const std::vector<std::string> &tags, bool isVegeterian, int minutes_to_ready, double rating);

private:
    std::pair<int, int> minutesToReadyFilter;
};
#endif