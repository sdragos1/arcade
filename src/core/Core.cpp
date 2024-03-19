/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include <iostream>
#include "Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

void Core::helpMessage()
{
    std::cout << "USAGE: ./arcade library" << std::endl;
    std::cout << "\tlibrary is the the graphics library to use initially" << std::endl;
}
