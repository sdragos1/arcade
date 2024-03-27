/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGame
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
   std::cout << "SnakeGame::compute" << std::endl;
}

const GameManifest &SnakeGame::getManifest() const noexcept
{
    return snakeGameManifest;
}

const Vector2u SnakeGame::getSize(void) const noexcept
{
    return {20, 20};
}

const entity::EntitiesMap &SnakeGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SnakeGame::getFps(void) const noexcept
{
    return 60;
}