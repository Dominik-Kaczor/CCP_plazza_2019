/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** IThread.hpp
*/

#include <vector>

#ifndef ITHREAD_HPP_
#define ITHREAD_HPP_

enum Status { STARTED = 0, RUNNING, DEAD };

class IThread {
public:
    virtual ~IThread() = default;
    virtual Status getStatus() = 0;
    virtual void waitDead() = 0;
    virtual void startThread() = 0;

protected:
private:
};

#endif /* !ITHREAD_HPP_ */
