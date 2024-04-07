/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** export
*/

#include "SnakeGameProvider.hpp"

extern "C" {
    shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
    {
        return shared::types::LibraryType::GAME;
    }

    shared::games::IGameProvider *SHARED_GAME_PROVIDER_GETTER_NAME(void)
    {
        return new SnakeGameProvider();
    }
}
