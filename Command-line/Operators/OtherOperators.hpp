#ifndef _OtherOperators_HPP_
#define _OtherOperators_HPP_
std::ostream &operator<<(std::ostream &out, const std::vector<std::string> &str);
std::vector<std::string> operator+(const std::vector<std::string> &str, std::string div);
std::vector<std::string> operator+(std::string div, const std::vector<std::string> &str);
#endif