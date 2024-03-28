/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** CoreUtils
*/

#include "CoreUtils.hpp"

CoreUtils::CoreUtils()
{
}


CoreUtils::~CoreUtils()
{
}

components::IKeyboardComponent::KeyData CoreUtils::convert(const events::IKeyEvent::KeyCode &keyCode,
    const events::IKeyEvent::KeyType &keyType)
{
    components::IKeyboardComponent::KeyData data;

    std::memcpy(&data.code, &keyCode, sizeof(events::IKeyEvent::KeyCode));
    std::memcpy(&data.type, &keyType, sizeof(events::IKeyEvent::KeyType));
    return data;
}