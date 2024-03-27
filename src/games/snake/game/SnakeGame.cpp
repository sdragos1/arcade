/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** Snake
*/

#include "SnakeGame.hpp"

SnakeGame::SnakeGame()
    :   _entities()
{
    SnakeHeadEntity head;
    _entities.push_back(std::make_shared<SnakeHeadEntity>(head));
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::compute(DeltaTime dt)
{
    (void)dt;
    std::cout << "bozo" << std::endl;
}

const GameManifest &SnakeGame::getManifest(void) const noexcept
{
    return snakeManifest;
}

const Vector2u SnakeGame::getSize(void) const noexcept
{
    return {20, 20};
}

const entity::EntitiesMap &SnakeGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SnakeGame::getFps() const noexcept
{
    return 60;
}
