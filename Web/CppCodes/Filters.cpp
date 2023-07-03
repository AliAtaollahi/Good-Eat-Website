#include "Filters/AllFilters.hpp"
#include "Errors/AllErrors.hpp"
#include "SideFuncs/SearchFuncs.hpp"
using namespace std;
void Filter::update(string tagFilter_) {}
void Filter::update(pair<int, int> minutesToReadyFilter_, string str,string str_) {}
void Filter::update(pair<double, double> ratingFilter_, bool isDouble) {}
void Filter::update() {}

TagFilter::TagFilter() : Filter() { tagFilter = ""; }
void TagFilter::clearFilter() { tagFilter = ""; }
void TagFilter::update(string tagFilter_) { tagFilter = tagFilter_; }
bool TagFilter::isPassFromFilter(const vector<string> &tags, bool isVegeterian, int minutes_to_ready, double rating)
{
    return (tagFilter != "" && search(tagFilter, tags, Error()) == NOT_FOUND) ? false : true;
}

TimeFilter::TimeFilter() : Filter() { minutesToReadyFilter = {NON_NUM, NON_NUM}; }
void TimeFilter::update(pair<int, int> minutesToReadyFilter_, string str,string str_)
{
    if (minutesToReadyFilter_.first > minutesToReadyFilter_.second || minutesToReadyFilter_.first < 0) throw BadRequest();
    minutesToReadyFilter = minutesToReadyFilter_;
}
void TimeFilter::clearFilter() { minutesToReadyFilter = {NON_NUM, NON_NUM}; }
bool TimeFilter::isPassFromFilter(const vector<string> &tags, bool isVegeterian, int minutes_to_ready, double rating)
{
    return (minutesToReadyFilter.first != NON_NUM && (minutes_to_ready < minutesToReadyFilter.first ||
                                                      minutes_to_ready > minutesToReadyFilter.second))
               ? false
               : true;
}

RateFilter::RateFilter() : Filter() { ratingFilter = {NON_NUM, NON_NUM}; }
void RateFilter::update(pair<double, double> ratingFilter_, bool isDouble)
{
    if (ratingFilter_.first > ratingFilter_.second ||
        ratingFilter_.first < MIN_SCORE - 1 || ratingFilter_.second > MAX_SCORE) throw BadRequest();
    ratingFilter = ratingFilter_;
}
void RateFilter::clearFilter() { ratingFilter = {NON_NUM, NON_NUM}; }
bool RateFilter::isPassFromFilter(const vector<string> &tags, bool isVegeterian, int minutes_to_ready, double rating)
{
    return (ratingFilter.first != NON_NUM && (rating < ratingFilter.first || rating > ratingFilter.second))
               ? false
               : true;
}

VegeterianFilter::VegeterianFilter() : Filter() { isVegeterianFilter = NON_NUM; }
void VegeterianFilter::update() { isVegeterianFilter = true; }
void VegeterianFilter::clearFilter() { isVegeterianFilter = NON_NUM; }
bool VegeterianFilter::isPassFromFilter(const vector<string> &tags, bool isVegeterian, int minutes_to_ready, double rating)
{

    return (isVegeterianFilter != NON_NUM && isVegeterian == false)
               ? false
               : true;
}