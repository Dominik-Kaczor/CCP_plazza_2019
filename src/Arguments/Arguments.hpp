/*
** EPITECH PROJECT, 2020
** Arguments
** File description:
** Arguments
*/

#ifndef ARGUMENTS_HPP_
#define ARGUMENTS_HPP_
#include <iostream>
#include <vector>

class ArgumentsError : public std::exception {
public:
    ArgumentsError(const std::string &);
    const char *what() const noexcept override;

private:
    std::string _message;
};
class Arguments {
public:
    Arguments(const int, const char **);
    ~Arguments();
    void SetRequired(const int);
    void CheckIfRequired();
    bool CheckAndPrint(const size_t, const std::string &, const std::string &);
    std::string GetAt(const size_t);
    void PrintStandardOutput(const std::string &);
    void PrintErrorOutput(const std::string &);

protected:
private:
    int _ac;
    int _minimum_required;
    std::vector<std::string> _av;
};

#endif /* !ARGUMENTS_HPP_ */