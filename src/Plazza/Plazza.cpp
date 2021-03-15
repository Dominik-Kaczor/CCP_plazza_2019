/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [SSH: 192.168.203.128]
** File description:
** Plazza
*/

#include "Plazza.hpp"

Plazza::Plazza()
{
    _myfile.open("log.txt");
    _nb_kichen = 0;
    _myfifo = strdup("/tmp/myfifo");
    mkfifo(_myfifo, 0666);
}

Plazza::~Plazza()
{
    _myfile.close();
}

void Plazza::SetValues(const unsigned int multipler,
                       const unsigned int cooks_per_kitchen,
                       const unsigned int time_ms)
{
    SetMultipler(multipler);
    SetCooksPerKitchen(cooks_per_kitchen);
    SetTimeInMS(time_ms);
}

void Plazza::SetMultipler(const unsigned int multipler)
{
    _multipler = multipler;
}

void Plazza::SetCooksPerKitchen(const unsigned int cooks_per_kitchen)
{
    _cooks_per_kitchen = cooks_per_kitchen;
}

void Plazza::SetTimeInMS(const unsigned int time_ms)
{
    _time_ms = time_ms;
}

bool Plazza::CheckExit(std::vector<std::string> array)
{
    std::fstream newfile;

    for (size_t i = 0; i < array.size(); i++) {
        if (std::strcmp(array[i].c_str(), "exit") == 0 && _nb_kichen > 0) {
            newfile.open(_myfifo, std::ios::out);
            newfile << "EXIT\n";
            newfile.close();
            return true;
        } else if (std::strcmp(array[i].c_str(), "exit") == 0)
            return true;
    }
    return false;
}

std::vector<std::string>
Plazza::ClearEmpty(std::vector<std::string> input_split)
{
    std::vector<std::string> array;
    std::vector<std::string>::iterator pend;

    pend = std::remove(input_split.begin(), input_split.end(), "");
    for (std::vector<std::string>::iterator p = input_split.begin(); p != pend;
         ++p)
        array.push_back(*p);
    return array;
}

std::vector<PizzaIngredient> Plazza::GetIngredient(PizzaType Pizza)
{
    std::vector<PizzaIngredient> Stock;

    switch (Pizza) {
    case 2: {
        Stock.push_back(Doe);
        Stock.push_back(Tomato);
        Stock.push_back(Gruyere);
        break;
    }
    case 1: {
        Stock.push_back(Doe);
        Stock.push_back(Tomato);
        Stock.push_back(Gruyere);
        Stock.push_back(Ham);
        Stock.push_back(Mushrooms);
        break;
    }
    case 4: {
        Stock.push_back(Doe);
        Stock.push_back(Tomato);
        Stock.push_back(Gruyere);
        Stock.push_back(Steak);
        break;
    }
    case 8: {
        Stock.push_back(Doe);
        Stock.push_back(Tomato);
        Stock.push_back(Egg);
        Stock.push_back(Goat);
        Stock.push_back(Love);
        break;
    }
    case -1:
        break;
    }
    return Stock;
}

int Plazza::GetTime(PizzaType Pizza)
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

void Plazza::ManagementKitchen(PizzaType Pizza)
{
    std::fstream newfile;
    std::string tp;
    std::string best_pid;
    int max = 0;

    newfile.open(_myfifo, std::ios::out);
    newfile << "STATUS\n";
    newfile.close();
    std::cout << "sa block pas ici 3" << std::endl;
    /* newfile.open(_myfifo, std::ios::in);
    std::cout << "sa block pas ici 4" << std::endl;
    while (getline(newfile, tp)) {
        std::stringstream stream_input(tp);
        while (std::getline(stream_input, tp, ' ')) {
            if (std::stoi(tp) > max) {
                max = std::stoi(tp);
                std::getline(stream_input, tp, ' ');
                best_pid = tp;
                break;
            }
        }
    }
    std::cout << "sa block pas ici 5" << std::endl;
    newfile.close();
    newfile.open(_myfifo, std::ios::out);
    newfile << best_pid << " " << Pizza << std::endl;
    newfile.close();
    std::cout << "sa block pas ici 6" << std::endl; */
}

bool Plazza::CheckKitchenSatured()
{
    std::fstream newfile;
    std::string tp;

    /* std::cout << "sa block pas ici 9" << std::endl;
    newfile.open(_myfifo, std::ios::out);
    newfile << "STATUS\n";
    newfile.close();
    std::cout << "sa block pas ici 10" << std::endl;
    newfile.open(_myfifo, std::ios::in);
    std::cout << "sa block pas ici 11" << std::endl;
    getline(newfile, tp);
    std::stringstream stream_input(tp);
    while (std::getline(stream_input, tp, ' ')) {
        if (std::stoi(tp) > 0)
            return false;
    }
    newfile.close(); */
    std::cout << "sa block pas ici 12" << std::endl;
    return true;
}

void Plazza::CheckActiveKitchen()
{
    std::fstream newfile;
    std::string tp;
    int counter = 0;

    std::cout << "sa block pas ici 7" << std::endl;
    newfile.open(_myfifo, std::ios::out);
    newfile << "LIVE\n";
    newfile.close();
    std::cout << "sa block pas ici 14" << std::endl;
    newfile.open(_myfifo, std::ios::in);
    getline(newfile, tp);
    std::stringstream stream_input(tp);
    while (std::getline(stream_input, tp, ' '))
        counter++;
    _nb_kichen = counter;
    newfile.close();
    std::cout << "sa block pas ici 8 " << counter << std::endl;
}

void Plazza::AddOrder(PizzaType Pizza, int Nb)
{
    std::cout << "sa block pas ici 1" << std::endl;
    for (int i = 0; i < Nb; i++) {
        if (_nb_kichen == 0 || CheckKitchenSatured() == true) {
            Process test(_nb_kichen);
            test.run();
            std::cout << "sa block pas ici 2" << std::endl;
            _nb_kichen++;
            ManagementKitchen(Pizza);
        } else
            ManagementKitchen(Pizza);
    }
    CheckActiveKitchen();
}

void Plazza::WriteOrder(std::string Pizza, std::string Size, int Nb)
{
    for (int i = 0; i < Nb; i++)
        _myfile << "Command " << Pizza << " " << Size << " achieve"
                << std::endl;
}

void Plazza::WriteBadOrder()
{
    _myfile << "Invalid command was realized" << std::endl;
}

bool Plazza::CheckSize(std::string Size)
{
    if (std::strcmp(Size.c_str(), "S") == 0)
        return false;
    if (std::strcmp(Size.c_str(), "M") == 0)
        return false;
    if (std::strcmp(Size.c_str(), "L") == 0)
        return false;
    if (std::strcmp(Size.c_str(), "XL") == 0)
        return false;
    if (std::strcmp(Size.c_str(), "XXL") == 0)
        return false;
    return true;
}

PizzaType Plazza::CheckType(std::string Type)
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

int Plazza::CheckNb(std::string Nb)
{
    if (Nb.at(0) != 'x')
        return -1;
    Nb.erase(0, 1);
    std::string copy = Nb;
    std::string::const_iterator it = Nb.begin();
    while (it != Nb.end() && std::isdigit(*it))
        ++it;
    if (!Nb.empty() && it == Nb.end())
        return std::stoi(copy);
    return -1;
}

bool Plazza::CheckOrder(std::vector<std::string> array)
{
    if (array.size() % 3 != 0)
        return true;
    for (size_t i = 0; i < array.size(); i = i + 3) {
        if (CheckType(array[i]) == -1)
            return true;
        if (CheckSize(array[i + 1]) == true)
            return true;
        if (CheckNb(array[i + 2]) == -1)
            return true;
    }
    return false;
}

void Plazza::OrderManagement(std::vector<std::string> array)
{
    if (CheckOrder(array) == true)
        WriteBadOrder();
    else {
        for (size_t i = 0; i < array.size(); i = i + 3) {
            //AddOrder(CheckType(array[i]), std::stoi(array[i + 2].erase(0, 1)));
            WriteOrder(array[i], array[i + 1], std::stoi(array[i + 2]));
        }
    }
}

void Plazza::Shell()
{
    std::string input;
    std::string second_split;
    std::vector<std::string> input_split;

    while (true) {
        input_split.clear();
        std::getline(std::cin, input);
        if (input == "")
            return;
        std::stringstream stream_input(input);
        while (std::getline(stream_input, input, ' ')) {
            std::stringstream stream_input_second(input);
            while (std::getline(stream_input_second, second_split, ';'))
                input_split.push_back(second_split);
        }
        if (CheckExit(input_split) == true)
            return;
        else
            OrderManagement(input_split);
    }
}