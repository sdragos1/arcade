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
#include <map>
#include <iostream>
#include <dirent.h>
#include "library/GameList.hpp"
#include "library/GraphicList.hpp"
#include "games/IGame.hpp"
#include "library/loader/Directory.hpp"
#include "types/Libraries.hpp"
#include "graphics/IGraphicsProvider.hpp"
#include "graphics/IWindow.hpp"
#include "graphics/events/IMouseButtonEvent.hpp"
#include "games/components/IComponent.hpp"
#include "games/components/ITextureComponent.hpp"
#include "games/components/IKeyboardComponent.hpp"
#include "games/components/ITextComponent.hpp"
#include "events/key/KeyPressedEvent.hpp"
#include "utils/CoreUtils.hpp"

#define USAGE_MESS "USAGE: ./arcade library\n\tlibrary is the the graphics library to use initially"
#define ICON_PATH "assets/window_icon.png"

using namespace shared::games;
using namespace shared::graphics;

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
            GO_MENU
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
        void _initGraphicLib();

        void _handleEntitiesKeyEvent(entity::EntitiesMap entities,
            std::shared_ptr<events::KeyPressedEvent> keyEvent);

        GeneralEventType _coreEvents(std::shared_ptr<events::KeyPressedEvent> keyEvent);

        void _handleEvents(entity::EntitiesMap entities);

        // Display Functions
        void _displayEntityTexture(std::shared_ptr<components::ITextureComponent> displayable);
        void _displayEntityText(std::shared_ptr<components::ITextComponent> displayable);
        void _displayEntities(entity::EntitiesMap entities);

        std::unique_ptr<GameList>       _librariesGame;
        std::unique_ptr<GraphicList>    _librariesRenderer;
        std::map<void *, std::shared_ptr<ITexture>> _textures;
        std::shared_ptr<shared::games::IGame> _currGame;
        IGraphicsProvider *_currRenderer;
        std::unique_ptr<IWindow> _currWindow;
};

typedef std::unique_ptr<Core> UniqueCore;


