#include "Errors/AllErrors.hpp"
#include "Members/AllMembers.hpp"
#include "MainObjects/Recipe.hpp"
#include "SideFuncs/AllFuncs.hpp"
#include "Operators/OtherOperators.hpp"
using namespace std;
int searchRatingByUser(shared_ptr<Member> newRecorder, const vector<shared_ptr<Rating>> &ratings)
{
    for (int i = 0; i < ratings.size(); i++)
        if (ratings[i]->recorder == newRecorder) return i;
    throw BadRequest();
}
int searchInEmails(string email, const vector<shared_ptr<Member>> &suppliers)
{
    for (int i = 0; i < suppliers.size(); i++)
        if (suppliers[i]->getEmail() == email) return i;
    return NOT_FOUND;
}
ostream &operator<<(ostream &out, const vector<string> &str)
{
    for (int i = 0; i < str.size(); i++) 
        out << str[i];
    return out;
}
vector<string> operator+(const vector<string> &str, string div)
{
    vector<string> str_ = str;
    for (int i = 0; i < str_.size() - 1; i++)
        str_[i] += div;
    return str_;
}
vector<string> operator+(string div, const vector<string> &str)
{
    vector<string> str_ = str;
    for (int i = 0; i < str_.size() - 1; i++)
        str_[i] += div;
    return str_;
}
bool isNumber(string str)
{
    char* end = nullptr;
    double val = strtod(str.c_str(), &end);
    return end != str.c_str() && *end == '\0' && val != HUGE_VAL;
}
vector<string> sortByOrder(const vector<string> &entry, int orderBy, char argumentDivider)
{
    vector<string> result, result_;
    int divider_;
    for (int i = 0; i < entry.size(); i++)
    {
        string divider = divideLine(entry[i], argumentDivider)[orderBy];
        result_.push_back(divider);
        sort(result_.begin(), result_.end());
        int indexOfElement = search(divider, result_, Error());
        result.insert(result.begin() + indexOfElement, entry[i]);
    }
    return result;
}
const vector<string> divideLine(string line, char divider)
{
    vector<string> dividedLine;
    string argument;
    istringstream arguments(line);
    while (getline(arguments, argument, divider))
    {
        if (argument == "") continue;
        dividedLine.push_back(argument);
    }
    return dividedLine;
}