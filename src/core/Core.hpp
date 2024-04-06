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

        /**
         * @brief Run the arcade main function
         * @return std::size_t
         */
        std::size_t runArcade();

        /**
         * @brief Get a bool value to tell if the arcade should be launched
         * @return bool
         */
        bool getLaunchArcade() const;

        /**
         * @brief run the menu
         */
        void runMenu();

    private:
        /**
         * @brief init the graphic lib
         */
        void _initGraphicLib();

        /**
         * @brief handle the graphic lib switch
         */
        void _handleGraphicSwitch();

        /**
         * @brief handle the collidable entities
         * @param collidable
         * @param collidableEntity
         */
        void _handleCollisions(std::shared_ptr<components::ICollidableComponent> collidable,
            entity::EntityPtr collidableEntity);

        /**
         * @brief handle the sound state
         * @param sound
         */
        void _handleSoundState(std::shared_ptr<components::ISoundComponent> sound);

        /**
         * @brief handle the mouse move event
         * @param sound
         */
        void _handleMouseMoveEvent(std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::MouseMoveEvent> mouseEvent);

        /**
         * @brief handle the mouse button released event
         * @param sound
         */
        void _handleMouseButtonReleasedEvent(
            std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::MouseButtonReleaseEvent> mouseEvent);

        /**
         * @brief handle the mouse button pressed event
         * @param displayable
         * @param mouseEvent
         */
        void _handleMouseButtonPressedEvent(
            std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::MouseButtonPressEvent> mouseEvent);

        /**
         * @brief handle the key release event
         * @param component
         * @param keyEvent
         */
        void _handleKeyReleaseEvent(std::shared_ptr<components::IKeyboardComponent> &component,
            std::shared_ptr<events::KeyReleaseEvent> keyEvent);

        /**
         * @brief handle the key pressed event
         * @param component
         * @param keyEvent
         */
        void _handleKeyPressEvent(std::shared_ptr<components::IKeyboardComponent> &component,
            std::shared_ptr<events::KeyPressedEvent> keyEvent);

        /**
         * @brief handle all the general events
         * @param keyEvent
         * @return int
         */
        int _handleGeneralEvents(std::shared_ptr<events::KeyPressedEvent> keyEvent);

        /**
         * @brief handle the entity events
         * @param entity
         * @param event
         */
        void _handleEntityEvents(entity::EntityPtr &entity, events::EventPtr event);

        /**
         * @brief handle the event of the arcade
         * @return std::size_t
         */
        std::size_t _handleEvents();

        /**
         * @brief handle the events of the menu
         * @param &indexGraphic
         * @param &indexGame
         * @param &name
         * @param &listNameGame
         * @param &listNameGraphic
         */
        void _eventsMenu(std::size_t &indexGraphic, std::size_t &indexGame, \
        shared::graphics::TextProps &name, \
        std::vector<shared::graphics::TextProps> &listNameGame,
        std::vector<shared::graphics::TextProps> &listNameGraphic); \

        /**
         * @brief handle the props of the menu game list
         * @return std::size_t
         */
        std::vector<shared::graphics::TextProps> _TextPropsListGame(std::size_t indexGame);

        /**
         * @brief handle the props of the menu game title
         * @return shared::graphics::TextProps
         */
        shared::graphics::TextProps _TextPropsTitleGame();

        /**
         * @brief handle the props of the menu graphic libs list
         * @return shared::graphics::TextProps
         */
        std::vector<shared::graphics::TextProps> _TextPropsListGraphic(std::size_t indexGraphic);

        /**
         * @brief handle the props of the menu graphic libs choice text
         * @return shared::graphics::TextProps
         */
        shared::graphics::TextProps _TextPropsTitleGraphic();

        /**
         * @brief handle the props of the player name text
         * @return shared::graphics::TextProps
         */
        shared::graphics::TextProps _TextPropsTitleName();

        /**
         * @brief handle the props of the typed player name
         * @return shared::graphics::TextProps
         */
        shared::graphics::TextProps _TextPropsName();

        // Display Functions
        /**
         * @brief display the displayable texture component of an entity
         * @param displayable
         */
        void _displayTexture(std::shared_ptr<components::ITextureComponent> displayable);

        /**
         * @brief display the displayable text component of an entity
         * @param displayable
         */
        void _displayText(std::shared_ptr<components::ITextComponent> displayable);

        /**
         * @brief display the displayables
         */
        void _displayManager();

        /**
         * @brief dipslay the libs in the menu
         * @param indexlib
         * @param listNamelib
         * @param titlelib
         */
        void _displaylib(std::size_t indexlib, \
        std::vector<shared::graphics::TextProps> listNamelib, \
        shared::graphics::TextProps titlelib);

        // Sound Functions

        std::unique_ptr<GameList>       _librariesGame;
        std::unique_ptr<GraphicList>    _librariesRenderer;
        std::map<void *, std::shared_ptr<ITexture>> _textures;
        std::shared_ptr<IGame> _currGame;
        IGraphicsProvider *_currRenderer;
        std::unique_ptr<IWindow> _currWindow;
        std::size_t _currLibIndex;
        shared::games::entity::EntitiesMap _gameEntities;
        bool _launchGame;
};

typedef std::unique_ptr<Core> UniqueCore;


