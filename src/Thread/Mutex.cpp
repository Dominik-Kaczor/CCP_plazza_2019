/*
** EPITECH PROJECT, 2019
** CCP_plazza_2019
** File description:
** Mutex.cpp
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
    pthread_mutex_init(&_mutex, nullptr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
}

pthread_mutex_t &Mutex::get_mutex()
{
    return _mutex;
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
}

bool Mutex::trylock()
{
    if (pthread_mutex_trylock(&_mutex))
        return false;
    return true;
}
