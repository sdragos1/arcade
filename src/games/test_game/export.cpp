/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** export
*/

#include "SnakeProvider.hpp"

extern "C" {
    shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
    {
        return shared::types::LibraryType::GAME;
    }

    shared::games::IGameProvider *SHARED_GAME_PROVIDER_GETTER_NAME(void)
    {
        return new SnakeProvider();
    }
}

