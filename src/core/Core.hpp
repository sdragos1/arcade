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
#include "../common/games/IGame.hpp"
#include "../common/types/Libraries.hpp"
#include "../common/graphics/IGraphicsProvider.hpp"

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
        std::vector<std::string>                                            _librariesPath;
        std::unique_ptr<LibraryList<shared::games::IGame>>                  _librariesGame;
        std::unique_ptr<LibraryList<shared::graphics::IGraphicsProvider>>   _librariesRenderer;
        
};

typedef std::unique_ptr<Core> UniqueCore;
