/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Cvariables.cpp
*/

#include "Cvariables.hpp"

Cvariables::Cvariables()
{
    pthread_cond_init(&_variable, nullptr);
}

Cvariables::~Cvariables()
{
    pthread_cond_destroy(&_variable);
}

void Cvariables::broadcast()
{
    pthread_cond_broadcast(&_variable);
}

void Cvariables::signal()
{
    pthread_cond_signal(&_variable);
}

void Cvariables::wait(Mutex &mutex)
{
    pthread_cond_wait(&_variable, &mutex.get_mutex());
}
