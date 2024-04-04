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
#include "games/components/ISoundComponent.hpp"
#include "games/components/ICollidableComponent.hpp"
#include "events/key/KeyPressedEvent.hpp"
#include "events/key/KeyReleaseEvent.hpp"
#include "events/mouse/MouseButtonPressEvent.hpp"
#include "events/mouse/MouseButtonReleaseEvent.hpp"
#include "events/mouse/MouseMoveEvent.hpp"
#include "utils/CoreUtils.hpp"

#define USAGE_MESS "USAGE: ./arcade library\n\tlibrary is the the graphics library to use initially"
#define ICON_PATH "assets/window_icon.png"
#define F1 1
#define F2 2
#define F3 3
#define BACK_MENU 1
#define QUIT_ARCADE 2

using namespace shared::games;
using namespace shared::graphics;

class Core
{
    public:
        typedef struct {
            std::shared_ptr<ISound> graphicSound;
            components::SoundState gameState;
            ISound::SoundState graphicState;
        } SoundMapProps;

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
        std::size_t runArcade();
        bool getLaunchArcade() const;
        void runMenu();

    private:
        void _initGraphicLib();
        void _handleGraphicSwitch();

        // Collision Functions
        void _handleCollisions(std::shared_ptr<components::ICollidableComponent> collidable,
            entity::EntityPtr collidableEntity);

        // Event Functions
        void _handleSoundState(std::shared_ptr<components::ISoundComponent> sound);

        void _handleMouseMoveEvent(std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::MouseMoveEvent> mouseEvent);

        void _handleMouseButtonReleasedEvent(
            std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::MouseButtonReleaseEvent> mouseEvent);

        void _handleMouseButtonPressedEvent(
            std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::MouseButtonPressEvent> mouseEvent);

        void _handleKeyReleaseEvent(std::shared_ptr<components::IKeyboardComponent> &component,
            std::shared_ptr<events::KeyReleaseEvent> keyEvent);

        void _handleKeyPressEvent(std::shared_ptr<components::IKeyboardComponent> &component,
            std::shared_ptr<events::KeyPressedEvent> keyEvent);

        int _handleGeneralEvents(std::shared_ptr<events::KeyPressedEvent> keyEvent);

        void _handleEntityEvents(entity::EntityPtr &entity, events::EventPtr event);

        std::size_t _handleEvents();

        void _eventsMenu(std::size_t &indexGraphic, std::size_t &indexGame, shared::graphics::TextProps &name, \
        std::vector<shared::graphics::TextProps> &listNameGame, std::vector<shared::graphics::TextProps> &listNameGraphic);

        std::vector<shared::graphics::TextProps> _TextPropsListGame(std::size_t indexGame);
        shared::graphics::TextProps _TextPropsTitleGame();

        std::vector<shared::graphics::TextProps> _TextPropsListGraphic(std::size_t indexGraphic);
        shared::graphics::TextProps _TextPropsTitleGraphic();

        shared::graphics::TextProps _TextPropsTitleName();
        shared::graphics::TextProps _TextPropsName();

        // Display Functions
        void _displayTexture(std::shared_ptr<components::ITextureComponent> displayable);
        void _displayText(std::shared_ptr<components::ITextComponent> displayable);
        void _displayManager();
        void _displaylib(std::size_t indexlib, std::vector<shared::graphics::TextProps> listNamelib, shared::graphics::TextProps titlelib);

        std::unique_ptr<GameList>       _librariesGame;
        std::unique_ptr<GraphicList>    _librariesRenderer;
        std::map<void *, std::shared_ptr<ITexture>> _textures;
        std::shared_ptr<IGame> _currGame;
        IGraphicsProvider *_currRenderer;
        std::unique_ptr<IWindow> _currWindow;
        std::size_t _currLibIndex;
        shared::games::entity::EntitiesMap _gameEntities;
        std::map<std::shared_ptr<components::ISoundComponent>,
            SoundMapProps> _soundsMap;
        bool _launchGame;
};

typedef std::unique_ptr<Core> UniqueCore;


