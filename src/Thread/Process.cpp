/*
** EPITECH PROJECT, 2020
** plazza
** File description:
** Process
*/

#include <ostream>
#include <iostream>
#include "Process.hpp"
#include "Constants.hpp"
#include "Plazza/Plazza.hpp"

void *cook(void *status)
{
    Orders infos = (Orders &)status;
    std::this_thread::sleep_for(std::chrono::seconds(infos.getTime()));
    printf("C'est finis\n");
    return (nullptr);
}

Process::Process(int cookers): _nbCookers(cookers)
{
    _Cookers.resize(_nbCookers);
}

Process::~Process()
{
}

int Process::get_empty_pos()
{
    for (int i = 0; i < _nbCookers; i++) {
        if (_Cookers[i].getStatus() != Status::RUNNING)
            return (i);
    }
    return (Constants::_EXIT_FAILURE);
}

int Process::get_nb_empty_process()
{
    int count = 0;

    for (size_t i = 0; i < _Cookers.size(); i++) {
        if (_Cookers[i].getStatus() != Status::RUNNING) {
            count++;
        }
    }
    return count;
}

void Process::wait_all()
{
    for (size_t i = 0; i < _Cookers.size(); i++) {
        _Cookers[i].waitDead();
    }
}

PizzaType Process::CheckType(std::string Type)
{
    if (std::strcmp(Type.c_str(), "regina") == 0)
        return Regina;
    if (std::strcmp(Type.c_str(), "margarita") == 0)
        return Margarita;
    if (std::strcmp(Type.c_str(), "americana") == 0)
        return Americana;
    if (std::strcmp(Type.c_str(), "fantasia") == 0)
        return Fantasia;
    return Undefined;
}

int Process::GetTime(PizzaType Pizza)
{
    switch (Pizza) {
    case 2:
        return 1;
    case 1:
        return 2;
    case 4:
        return 2;
    case 8:
        return 4;
    case -1:
        return -1;
    }
    return -1;
}

std::vector<std::string> Process::split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
        std::vector<std::string> splittedStrings;
    std::size_t i = 0;

    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    while (i < splittedStrings.size()) {
        if (splittedStrings[i] == "") {
            splittedStrings.erase(splittedStrings.begin() + i);
            i--;
        }
        i++;
    }
     	return splittedStrings;
}

void Process::run()
{
    std::fstream newfile;
    std::string tp;
    std::string tp_split;
    pid_t pid = fork();
    int nm_pid = getpid();
    char *myfifo = strdup("/tmp/myfifo");
    std::string pid_str = std::to_string(nm_pid);
    mkfifo(myfifo, 0666);
    int empty = 0;

    if (pid == 0) {
        while (true) {
            newfile.open(myfifo, std::ios::in);
            getline(newfile, tp);
            std::stringstream stream_input(tp_split);
            while (std::getline(stream_input, tp_split, ' ')) {
                if (std::strcmp(tp_split.c_str(), "EXIT") == 0)
                    exit(0);
                if (std::strcmp(tp_split.c_str(), "LIVE") == 0) {
                    newfile.close();
                    newfile.open(myfifo, std::ios::out);
                    newfile << "Present ";
                }
                if (std::strcmp(tp_split.c_str(), "STATUS") == 0) {
                    newfile.close();
                    usleep(1000);
                    newfile.open(myfifo, std::ios::out);
                    newfile << get_nb_empty_process() << " " << pid_str << std::endl;
                }
                if (std::strcmp(tp_split.c_str(), pid_str.c_str()) == 0) {
                    empty = get_empty_pos();
                    if (empty != 84) {
                        Orders it(GetTime(CheckType(split(tp, ' ')[1])) * (std::stoi(split(tp, ' ')[2])));
                        _Cookers[empty].startThread(cook, it);
                    }
                }
            }
            newfile.close();
        }
        wait_all();
    }
}