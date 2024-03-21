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
#include <iostream>
#include <dirent.h>
#include "library/LibraryList.hpp"
#include "library/loader/Directory.hpp"
#include "../common/games/game/IGame.hpp"
#include "../common/types/LibraryType.hpp"
#include "../common/rendering/IRenderer.hpp"

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
        std::vector<std::string>                                       _librariesPath;
        std::unique_ptr<LibraryList<shared::games::game::IGame>>       _librariesGame;
        std::unique_ptr<LibraryList<shared::rendering::IRenderer>>     _librariesRenderer;
        
};

typedef std::unique_ptr<Core> UniqueCore;
