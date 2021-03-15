/*
** EPITECH PROJECT, 2020
** Cvariables
** File description:
** plazza
*/

#ifndef CVARIABLES_HPP_
#define CVARIABLES_HPP_

#include <condition_variable>
#include "Mutex.hpp"

class Cvariables {
    public:
        Cvariables();
        ~Cvariables();

        void broadcast();
        void signal();
        void wait(Mutex &mutex);
    protected:
    private:
    pthread_cond_t _variable;
};

#endif /* !CVARIABLES_HPP_ */
