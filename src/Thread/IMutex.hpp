/*
** EPITECH PROJECT, 2020
** The Plazza
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
#define IMUTEX_HPP_

class IMutex {
public:
    virtual ~IMutex() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual bool trylock() = 0;
};

#endif /* !IMUTEX_HPP_ */
