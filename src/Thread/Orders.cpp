/*
** EPITECH PROJECT, 2020
** plazza
** File description:
** Orders
*/

#include "Orders.hpp"

Orders::Orders(int time) : _time(time)
{
}

int Orders::getTime()
{
    return _time;
}

Orders::~Orders()
{
}
