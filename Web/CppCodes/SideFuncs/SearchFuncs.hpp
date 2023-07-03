#ifndef _SearchFuncs_HPP_
#define _SearchFuncs_HPP_
#include "../Errors/AllErrors.hpp"
template <typename T, typename S>
int search(T target, const std::vector<S> &range, Error e)
{
    for (int i = 0; i < range.size(); i++)
        if (target == range[i]) return i;
    if (e.getText() != "") throw e;
    return NOT_FOUND;
}
int searchRatingByUser(std::shared_ptr<Member> newRecorder, const std::vector<std::shared_ptr<Rating>> &ratings);
#endif