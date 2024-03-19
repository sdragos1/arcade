/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#pragma once

#include <string>
#include <memory>
#include <vector>

class Core
{
    public:

        /**
         * @brief Constructor of Core Class
         *
         */
        Core();

        /**
         * @brief Destructor of Core Class
         *
         */
        ~Core();

        /**
         * @brief Display how to use the arcade binary
         *
         */
        void helpMessage();


    private:
        std::vector<std::string> _LibrariesPath;
        
};

typedef std::unique_ptr<Core> UniqueCore;
