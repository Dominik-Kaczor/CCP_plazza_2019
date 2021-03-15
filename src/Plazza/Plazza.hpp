/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [SSH: 192.168.203.128]
** File description:
** Plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h> 

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

#include "Pizza.hpp"
#include "Thread/Process.hpp"

class Plazza {
    public:
        Plazza();
        ~Plazza();
        void SetValues(const unsigned int, const unsigned int, const unsigned int);
        void SetMultipler(const unsigned int);
        void SetCooksPerKitchen(const unsigned int);
        void SetTimeInMS(const unsigned int);
        void LaunchPlazza();
        void Shell();
        bool CheckExit(std::vector<std::string>);
        void OrderManagement(std::vector<std::string>);
        std::vector<std::string> ClearEmpty(std::vector<std::string>);
        bool CheckOrder(std::vector<std::string>);
        bool CheckSize(std::string);
        PizzaType CheckType(std::string);
        int CheckNb(std::string);
        void WriteOrder(std::string, std::string, int);
        void AddOrder(PizzaType, int);
        void WriteBadOrder();
        int GetTime(PizzaType);
        void ManagementKitchen(PizzaType);
        bool CheckKitchenSatured();
        void CheckActiveKitchen();
        std::vector<PizzaIngredient> GetIngredient(PizzaType);
    private:
        unsigned int _multipler;
        unsigned int _cooks_per_kitchen;
        unsigned int _time_ms;
        std::vector<std::vector<PizzaIngredient>> _list_arg;
        std::vector<int> _list_int;
        std::ofstream _myfile;
        int _nb_kichen;
        char *_myfifo;
};

#endif /* !PLAZZA_HPP_ */