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
#include "games/IGame.hpp"
#include "library/loader/Directory.hpp"
#include "types/Libraries.hpp"
#include "graphics/IGraphicsProvider.hpp"
#include "games/components/IComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"
#include "games/components/IKeyboardComponent.hpp"

#define USAGE_MESS "USAGE: ./arcade library\n\tlibrary is the the graphics library to use initially"

class Core
{
    public:
        typedef enum {
            NONE,
            EXIT,
            RESTART_GAME,
            NEXT_GAME,
            PREV_GAME,
            NEXT_GRAPHICS,
            PREV_GRAPHICS,
        } GeneralEventType;

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

        void runArcade();

    private:
        void _init();

        GeneralEventType _handleEvents(std::vector<shared::graphics::events::Event> events,
        shared::games::entity::EntitiesMap entities);


        void _displayEntities(shared::games::entity::EntitiesMap entities);
        void _displayEntity(std::shared_ptr<shared::games::components::IDisplayableComponent> displayable);

        std::unique_ptr<GameList>       _librariesGame;
        std::unique_ptr<GraphicList>    _librariesRenderer;
        std::map<void *, std::shared_ptr<shared::graphics::ITexture>> _textures;
        std::shared_ptr<shared::games::IGame> _currGame;
        std::shared_ptr<shared::graphics::IGraphicsProvider> _currRenderer;
        std::unique_ptr<shared::graphics::IWindow> _currWindow;
};

typedef std::unique_ptr<Core> UniqueCore;
