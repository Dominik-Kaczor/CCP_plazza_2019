/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Orders.hpp
*/

#ifndef ORDERS_HPP_
#define ORDERS_HPP_

#include <vector>
#include <string>
#include "Plazza/Pizza.hpp"

class Orders {
    public:
        Orders(int time);
        ~Orders();
        int getTime();
    private:
        int _time;
};

#endif /* !THREAD_HPP_ */