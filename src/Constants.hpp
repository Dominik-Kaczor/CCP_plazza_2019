/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [SSH: 192.168.203.128]
** File description:
** Constants
*/

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_
#include <vector>
#include <iostream>
#include <string>

typedef unsigned int uint;
typedef unsigned short ushort;

#define STR_UINT(x) std::stoul(x, nullptr, 0)

namespace Constants {
    static const int _EXIT_SUCCESS = 0;
    static const int _EXIT_FAILURE = 84;
    static const int MINIMAL_ARGUMENTS = 4;
    static const int LIBC_ERROR = -1;
    static const std::string STRING_NULL = "NULL";
    static const std::string FLAG_HELP = "--help";
    static const std::string FLAG_HELP_LITTLE = "-h";
    static const std::string USAGE =
        "USAGE\n\t./plazza t c s \n\nDESCRIPTION\n\t"
        "t\tmultiplier for the cooking time of the pizzas\n\t"
        "c\tthe number of cooks per kitchen\n\t"
        "s\ttime in milliseconds, used by the kitchen stock to replace ingredients\n"
        "\nDESCRIPTION PROJECT\n\tThe purpose of this "
        "project is to make us realize a simulation of a pizzeria\n\twhich is "
        "composed of the reception that accepts new commands, of several "
        "kitchens\n\tthemselves with several cooks themselves cooking several "
        "pizzas.\n";
    static const std::string ERROR_ARGS = "Not enough arguments";
}; // namespace Constants

#endif /* !CONSTANTS_HPP_ */
