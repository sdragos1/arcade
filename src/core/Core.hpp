/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#pragma once

#include <string>
#include <memory>

class Core
{
    public:
        Core();
        ~Core();

        void helpMessage();
};

typedef std::unique_ptr<Core> UniqueCore;
