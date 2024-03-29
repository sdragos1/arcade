/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** CoreUtils
*/

#pragma once

#include <cstring>
#include "graphics/events/IKeyEvent.hpp"
#include "games/components/IKeyboardComponent.hpp"
#include "graphics/types/TextProps.hpp"
#include "games/components/ITextComponent.hpp"

using namespace shared::graphics;
using namespace shared::games;

class CoreUtils {
    public:
        CoreUtils();
        ~CoreUtils();

        static components::IKeyboardComponent::KeyData
            convertKey(const events::IKeyEvent::KeyCode& keyCode,
            const events::IKeyEvent::KeyType& keyType);

        static TextAlign mapTextAlign(
            const components::ITextComponent::TextAlign& align);

        static TextVerticalAlign mapTextVerticalAlign(
            const components::ITextComponent::TextVerticalAlign& align);
};
