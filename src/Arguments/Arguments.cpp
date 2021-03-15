/*
** EPITECH PROJECT, 2020
** Arguments
** File description:
** Arguments
*/

#include "Arguments.hpp"
#include "Constants.hpp"

ArgumentsError::ArgumentsError(const std::string &message)
{
    _message = message;
}

const char *ArgumentsError::what() const noexcept
{
    return (_message.data());
}

Arguments::Arguments(const int ac, const char **av)
{
    _ac = ac;

    for (int i = 0; i != ac; i++) {
        _av.push_back(std::string(av[i]));
    }
}

std::string Arguments::GetAt(const size_t pos)
{
    std::string str;

    try {
        str = _av.at(pos);
    } catch (std::out_of_range &e) {
        return (Constants::STRING_NULL);
    }
    return (_av.at(pos));
}

void Arguments::SetRequired(const int required)
{
    _minimum_required = required;
}

void Arguments::CheckIfRequired()
{
    if (_ac != _minimum_required) {
        throw ArgumentsError(Constants::ERROR_ARGS);
    }
}

void Arguments::PrintStandardOutput(const std::string &print)
{
    std::cout << print << std::endl;
}

void Arguments::PrintErrorOutput(const std::string &print)
{
    std::cerr << print << std::endl;
}

bool Arguments::CheckAndPrint(const size_t pos,
                                      const std::string &to_compare,
                                      const std::string &to_print)
{
    if (GetAt(pos) == to_compare) {
        PrintStandardOutput(to_print);
        return (true);
    } else {
        return (false);
    }
}

Arguments::~Arguments()
{
}