/*
** EPITECH PROJECT, 2020
** Thread
** File description:
** Plazza
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "IThread.hpp"
#include "Mutex.hpp"
#include "Orders.hpp"
#include <thread>
#include <vector>

class Thread {
public:
    Thread();
    ~Thread();
    Status getStatus();
    void waitDead();
    void startThread(void *(func)(void *), Orders &data);

protected:
private:
    Status _status;
    pthread_t _thread;
    Mutex _mutex;
};

#endif /* !THREAD_HPP_ */
