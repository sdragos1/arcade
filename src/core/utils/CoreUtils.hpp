/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** CoreUtils
*/

#pragma once

#include <cstring>
#include "graphics/types/TextProps.hpp"
#include "games/components/ITextComponent.hpp"
#include "games/components/IKeyboardComponent.hpp"
#include "games/components/ISoundComponent.hpp"
#include "games/components/ICollidableComponent.hpp"
#include "graphics/events/IKeyEvent.hpp"
#include "graphics/events/IMouseEvent.hpp"
#include "graphics/ISound.hpp"

using namespace shared::graphics;
using namespace shared::games;

class CoreUtils {
    public:
        /**
         * @brief Construct a new Core Utils object
         */
        CoreUtils();

        /**
         * @brief Destroy the Core Utils object
         */
        ~CoreUtils();

        /**
         * @brief Convert a key data
         * @param align
         * @return std::string
         */
        static components::IKeyboardComponent::KeyData
            convertKey(const events::IKeyEvent::KeyCode& keyCode,
            const events::IKeyEvent::KeyType& keyType);

        /**
         * @brief Allign a text component
         * @param align
         * @return TextAlign
         */
        static TextAlign mapTextAlign(
            const components::ITextComponent::TextAlign& align);

        /**
         * @brief Vertically align a text component
         * @param align
         * @return TextVerticalAlign
         */
        static TextVerticalAlign mapTextVerticalAlign(
            const components::ITextComponent::TextVerticalAlign& align);

        /**
         * @brief Check if a displayable component is pressed
         * @param displayable
         * @param mouseEvent
         * @return bool
         */
        static bool isDisplayablePressed(
            std::shared_ptr<components::IDisplayableComponent> displayable,
            std::shared_ptr<events::IMouseEvent> mouseEvent);

        /**
         * @brief Map a sound state paused / stopped / playing
         * @param state
         * @return shared::graphics::ISound::SoundState
         */
        static shared::graphics::ISound::SoundState mapSoundState(
            const shared::games::components::SoundState state);

        /**
         * @brief Check if two collidable components are colliding
         * @param collidable1
         * @param collidable2
         * @return true
         * @return false
         */
        static bool checkCollision(
            std::shared_ptr<components::ICollidableComponent> collidable1,
            std::shared_ptr<components::ICollidableComponent> collidable2);
};
