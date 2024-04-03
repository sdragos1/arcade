/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeProvider
*/

#include "SnakeProvider.hpp"

SnakeProvider::SnakeProvider()
{
}

SnakeProvider::~SnakeProvider()
{
}

const GameManifest &SnakeProvider::getManifest() const noexcept
{
    return snakeManifest;
}

std::shared_ptr<IGame> SnakeProvider::createInstance(void)
{
    return std::make_shared<SnakeGame>();
}


extern "C" shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
{
    return shared::types::LibraryType::GAME;
}

extern "C" shared::games::IGameProvider *SHARED_GAME_PROVIDER_GETTER_NAME(void)
{
    return new SnakeProvider();
}
