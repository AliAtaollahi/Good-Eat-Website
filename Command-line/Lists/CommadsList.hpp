#ifndef _CommandsList_HPP_
#define _CommandsList_HPP_
#include "../Definitions/ClassNames.hpp"
#include "../Definitions/Consts.hpp"
#include "../Definitions/Libraries.hpp"
const std::string NOT_MATTER = "";
const std::string MUST_BE_NUM = " ";
const std::string MUST_BE_INT = "  ";
const std::string MUST_BE_YES_OR_NO = "   ";
const std::vector<std::vector<std::string>> CMDS = {
    {"POST", "signup", "?", "username", NOT_MATTER, "password", NOT_MATTER, "type", NOT_MATTER},
    {"POST", "login", "?", "username", NOT_MATTER, "password", NOT_MATTER},
    {"POST", "logout"},
    {"POST", "recipes", "?", "title", NOT_MATTER, "ingredients", NOT_MATTER, "vegetarian", MUST_BE_YES_OR_NO, "minutes_to_ready", MUST_BE_NUM, "tags", NOT_MATTER, "image_address", NOT_MATTER},
    {"POST", "rates", "?", "recipe_id", MUST_BE_INT, "score", MUST_BE_NUM},
    {"POST", "shelves", "?", "name", NOT_MATTER},
    {"POST", "filters", "?", "tag", NOT_MATTER},
    {"POST", "filters", "?", "vegetarian"},
    {"POST", "filters", "?", "min-minutes", MUST_BE_NUM, "max-minutes", MUST_BE_NUM},
    {"POST", "filters", "?", "min_rating", MUST_BE_NUM, "max_rating", MUST_BE_NUM},
    {"GET", "recipes"},
    {"GET", "recipes", "?", "id", MUST_BE_INT},
    {"GET", "shelves", "?", "username", NOT_MATTER, "limit", MUST_BE_INT},
    {"GET", "shelves_recipes", "?", "shelf_id", MUST_BE_INT},
    {"GET", "chefs"},
    {"GET", "chefs", "?", "chef_username", NOT_MATTER},
    {"GET", "users"},
    {"GET", "my_recipes"},
    {"PUT", "rates", "?", "recipe_id", MUST_BE_INT, "score", MUST_BE_NUM},
    {"PUT", "shelves_recipes", "?", "shelf_id", MUST_BE_INT, "recipe_id", MUST_BE_INT},
    {"DELETE", "recipes", "?", "id", MUST_BE_INT},
    {"DELETE", "filters"},
    {"DELETE", "shelves_recipes", "?", "shelf_id", MUST_BE_INT, "recipe_id", MUST_BE_INT},
    {"POST", "signup_supplier", "?", "name", NOT_MATTER, "email", NOT_MATTER, "password", NOT_MATTER},
    {"POST", "offers", "?", "ingredient", NOT_MATTER, "price", MUST_BE_NUM, "count", MUST_BE_INT, "packaging", MUST_BE_NUM},
    {"PUT", "offers", "?", "ingredient", NOT_MATTER, "price", MUST_BE_NUM, "count", MUST_BE_INT},
    {"DELETE", "offers", "?", "ingredient", NOT_MATTER},
    {"GET", "credits"},
    {"PUT", "credits", "?", "money", MUST_BE_NUM},
    {"POST", "orders", "?", "recipe_id", MUST_BE_INT},
    {"GET", "orders"},
    {"POST", "login", "?", "email", NOT_MATTER, "password", NOT_MATTER}};
enum PostCommands
{
    SIGNUP = 1,
    LOGIN = 2,
    LOGOUT = 3,
    POST_RECIPES = 4,
    POST_RATES = 5,
    POST_SHELVES = 6,
    POST_FILTERS_POS_1 = 7,
    POST_FILTERS_POS_2 = 8,
    POST_FILTERS_POS_3 = 9,
    POST_FILTERS_POS_4 = 10,
    GET_RECIPES_POS_1 = 11,
    GET_RECIPES_POS_2 = 12,
    GET_SHELVES = 13,
    GET_SHELVES_RECIPES = 14,
    GET_CHEFS_POS_1 = 15,
    GET_CHEFS_POS_2 = 16,
    GET_USERS = 17,
    GET_MY_RECIPES = 18,
    PUT_RATES = 19,
    PUT_SHELVES_RECIPES = 20,
    DELETE_RECIPES = 21,
    DELETE_FILTERS = 22,
    DELETE_SHELVES_RECIPES = 23,
    SIGNUP_SUPPLIER = 24,
    POST_OFFERS = 25,
    PUT_OFFERS = 26,
    DELETE_OFFERS = 27,
    GET_CREDITS = 28,
    PUT_CREDITS = 29,
    POST_ORDERS = 30,
    GET_ORDERS = 31,
    SUPPLIER_LOGIN = 32
};
#endif