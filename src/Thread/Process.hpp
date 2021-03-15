/*
** EPITECH PROJECT, 2020
** plazza
** File description:
** Process
*/

#include "Thread.hpp"
#include <vector>
#include <sys/types.h>
#include <unistd.h>

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

class Process {
    public:
        Process(int cookers);
        ~Process();

        int get_empty_pos();
        int get_nb_empty_process();
        void run();
        PizzaType CheckType(std::string Type);
        int GetTime(PizzaType Pizza);
        void wait_all();
        std::vector<std::string> split(std::string, char);

    protected:
    private:
    int _nbCookers;
    std::vector<Thread> _Cookers;
};

#endif /* !PROCESS_HPP_ */
