/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGameProvider
*/

#include "SnakeGameProvider.hpp"

SnakeGameProvider::SnakeGameProvider()
{
}

SnakeGameProvider::~SnakeGameProvider()
{
}

const GameManifest &SnakeGameProvider::getManifest() const noexcept
{
    return snakeGameManifest;
}

std::shared_ptr<IGame> SnakeGameProvider::createInstance()
{
    return std::make_shared<SnakeGame>();
}
