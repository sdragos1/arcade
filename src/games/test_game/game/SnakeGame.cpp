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
    std::shared_ptr<entity::IEntity> head = std::make_shared<SnakeHeadEntity>();
    std::shared_ptr<entity::IEntity> score = std::make_shared<ScoreEntity>();
    _entities.push_back(head);
    _entities.push_back(score);
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::compute(DeltaTime dt)
{
    (void)dt;
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
