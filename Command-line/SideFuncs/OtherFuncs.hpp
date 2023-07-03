#ifndef _OtherFuncs_HPP_
#define _OtherFuncs_HPP_
bool isNumber(std::string entry);
std::vector<std::string> sortByOrder(const std::vector<std::string> &entry, int orderBy, char argumentDivider);
const std::vector<std::string> divideLine(std::string line, char divider);
#endif