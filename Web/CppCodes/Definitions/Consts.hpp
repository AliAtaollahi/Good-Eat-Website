#ifndef _Consts_HPP_
#define _Consts_HPP_
#include "../Definitions/Libraries.hpp"
const std::string NOT_MATTER = "";
const std::string MUST_BE_NUM = " ";
const std::string MUST_BE_INT = "  ";
const std::string MUST_BE_YES_OR_NO = "   ";
const std::vector<std::string> MEMBERS = {"chef", "user"};
enum Members {
  CHEF = 0,
  USER = 1,
  SUPPLIER = 2
};
const std::vector<std::string> VEGETERIAN_POS = {"No", "Yes"};
enum VegeterianPos {
  NO = 0,
  YES = 1
};
enum CommandsOrder {
  NAME_ORDER = 1,
  TITLE = 0,
  INGREDIENTS = 1,
  TYPE = 4,
  MINUTES_TO_READY = 2,
  TAGS = 3,
  IMAGE = 5,
};
enum Filters {
  TAG_FILTER = 0,
  RATE_FILTER = 1,
  MIN_FILTER = 2,
  VEGETERIAN_POS_FILTER = 3
};
const int END_PROGRAM = 0;
const int NOT_END_PROGRAM = 1;
const int FOUND = 1;
const int EMPTY = 0;
const int NOT_FOUND = -1;
const double NOT_RATING = 0;
const int MIN_COMMAND_LENGTH = 2;
const int MAX_SCORE = 5;
const int MIN_SCORE = 1;
const int NON_NUM = -1;
const int DIGIT_NUM = 1;
const int DIGIT_NUM_TOTAL_COST = 0;
const int NO_MONEY = 0;
const int NO_MATERIAL = 0;
const int COUNT_FOR_DISCOUNT = 20;
const double NO_DISCOUNT = 1;
const double DISCOUNT = 0.9;
const int PORT = 5000 ;
const std::string NOT_ENTERED = "-1";
#endif