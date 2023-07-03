#ifndef _Consts_HPP_
#define _Consts_HPP_
#include "../Definitions/Libraries.hpp"
const std::vector<std::string> MEMBERS = {"chef", "user"};
enum Members
{
    CHEF = 0,
    USER = 1,
    SUPPLIER = 2
};
const std::vector<std::string> VEGETERIAN_POS = {"No", "Yes"};
enum VegeterianPos
{
    NO = 0,
    YES = 1
};
enum CommandsOrder
{
    MAIN_COMMAND = 0,
    NAME_ORDER = 1,
    SUB_COMMAND = 1,
    TITLE = 4,
    USERNAME = 4,
    NAME = 4,
    ID_1 = 4,
    ID_2 = 6,
    FILTER_TAG = 4,
    FILTER_MIN_1 = 4,
    FILTER_MIN_2 = 6,
    FILTER_RATE_1 = 4,
    FILTER_RATE_2 = 6,
    INGREDIENTS = 6,
    PASSWORD = 6,
    POST_RATE = 6,
    PUT_RATE = 6,
    LIMIT = 6,
    TYPE = 8,
    MINUTES_TO_READY = 10,
    TAGS = 12,
    IMAGE = 14,
    EMAIL_SIGNUP = 6,
    EMAIL_LOGIN = 4,
    SUPPLIER_PASSWORD = 8,
    INGREDIENTS_POST = 4,
    PRICE = 6,
    COUNT = 8,
    PACKAGING = 10,
    MONEY = 4
};
enum Filters
{
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
#endif