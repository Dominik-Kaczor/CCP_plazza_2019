/*
** EPITECH PROJECT, 2019
** CCP_plazza_2019
** File description:
** Thread.cpp
*/

#include "Thread.hpp"

Thread::Thread()
{
    _status = Status::RUNNING;
}

Thread::~Thread()
{
    _status = Status::DEAD;
    _mutex.unlock();
}

Status Thread::getStatus()
{
    if (_mutex.trylock()) {
        _status = Status::STARTED;
        _mutex.unlock();
    }
    return _status;
}

void Thread::waitDead()
{
    pthread_join(_thread, nullptr);
}

void Thread::startThread(void *(func)(void *), Orders &data)
{
    if (_mutex.trylock()) {
        if (pthread_create(&_thread, nullptr, func, &data) != 0) {
            _mutex.unlock();
        } else {
            _status = Status::RUNNING;
        }
    }
}
