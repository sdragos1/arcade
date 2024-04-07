/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

int main(int argc, char **argv)
{
    (void) argv;
    UniqueCore arcadeCore = nullptr;
    std::size_t resultArcade = 0;

    try {
        if (argc != 2) {
            std::cout << USAGE_MESS << std::endl;
            return 84;
        }
        std::string defaultLib(argv[1]);
        arcadeCore = std::make_unique<Core>(defaultLib);
        while (true) {
            arcadeCore->runMenu();
            if (arcadeCore->getLaunchArcade() == true) {
                resultArcade = arcadeCore->runArcade();
                if (resultArcade == QUIT_ARCADE)
                    break;
            } else {
                break;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // return 84;
    }
}
