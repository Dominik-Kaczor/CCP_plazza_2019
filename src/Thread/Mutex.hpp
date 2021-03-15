/*
** EPITECH PROJECT, 2020
** ThePlazza
** File description:
** Mutex
*/

#include <thread>
#include <mutex>
#include "IMutex.hpp"

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

class Mutex : public IMutex {
public:
    Mutex();
    ~Mutex();

    pthread_mutex_t &get_mutex();
    void lock();
    void unlock();
    bool trylock();

private:
    pthread_mutex_t _mutex;
};

#endif /* !MUTEX_HPP_ */
