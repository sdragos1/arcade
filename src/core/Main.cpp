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
    UniqueCore arcadeCore = std::make_unique<Core>();

    if (argc != 2) {
        arcadeCore->helpMessage();
        return 84;
    }
}
