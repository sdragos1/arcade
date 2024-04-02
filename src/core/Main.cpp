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

    try {
        if (argc != 2) {
            std::cout << USAGE_MESS << std::endl;
            return 84;
        }
        std::string defaultLib(argv[1]);
        arcadeCore = std::make_unique<Core>(defaultLib);
        arcadeCore->runArcade();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
