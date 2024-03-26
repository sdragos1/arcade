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
#include "library/GameList.hpp"
#include "library/GraphicList.hpp"
#include "../common/games/IGame.hpp"
#include "library/loader/Directory.hpp"
#include "../common/types/Libraries.hpp"
#include "../common/graphics/IGraphicsProvider.hpp"
#include "../common/graphics/events/key/KeyPressEvent.hpp"

#define USAGE_MESS "USAGE: ./arcade library\n\tlibrary is the the graphics library to use initially"

class Core
{
    public:
        /**
         * @brief Constructor of Core Class
         *
         */
        explicit Core(std::string defaultLib);

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

        void handleEntities(std::vector<shared::graphics::EntityProps> entities);
        bool handleEvents(std::vector<shared::graphics::events::Event> events);
        void runArcade();

    private:
        std::vector<std::string>        _librariesPath;
        std::unique_ptr<GameList>       _librariesGame;
        std::unique_ptr<GraphicList>    _librariesRenderer;
};

typedef std::unique_ptr<Core> UniqueCore;
