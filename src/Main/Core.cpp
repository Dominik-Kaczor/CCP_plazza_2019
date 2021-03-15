/*
** EPITECH PROJECT, 2020
** Core
** File description:
** Core
*/

#include <memory>
#include "Constants.hpp"
#include "Plazza/Plazza.hpp"
#include "Arguments/Arguments.hpp"

int core(int ac, char **av)
{
    std::unique_ptr<Arguments> Args(new Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    std::unique_ptr<Plazza> _Plazza(new Plazza());
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
        if (Args->CheckAndPrint(1, Constants::FLAG_HELP, Constants::USAGE) ==
            true)
            return (Constants::_EXIT_SUCCESS);
        _Plazza->SetValues(STR_UINT(Args->GetAt(1)), STR_UINT(Args->GetAt(2)), STR_UINT(Args->GetAt(3)));
        _Plazza->Shell();
    } catch (const ArgumentsError &error) {
        Args->PrintErrorOutput(Constants::USAGE);
        return (Constants::_EXIT_FAILURE);
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return (Constants::_EXIT_FAILURE);
    }
    return (Constants::_EXIT_SUCCESS);
}
