/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** CoreUtils
*/

#pragma once

#include "graphics/events/IKeyEvent.hpp"
#include "games/components/IKeyboardComponent.hpp"
#include <cstring>

using namespace shared::graphics;
using namespace shared::games;

class CoreUtils {
    public:
        CoreUtils();
        ~CoreUtils();

        static components::IKeyboardComponent::KeyData
            convert(const events::IKeyEvent::KeyCode& keyCode, const events::IKeyEvent::KeyType& keyType);
};
