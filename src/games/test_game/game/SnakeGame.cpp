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
    _score = 0;
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::compute(DeltaTime dt)
{
    (void)dt;
    _time -= dt;
    if (_time > std::chrono::milliseconds(1000)) {
        _score += 1;
        _time = std::chrono::milliseconds(0);
    }
}

const GameManifest &SnakeGame::getManifest(void) const noexcept
{
    return snakeManifest;
}

const Vector2u SnakeGame::getSize(void) const noexcept
{
    return {48, 27};
}

const entity::EntitiesMap &SnakeGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SnakeGame::getFps() const noexcept
{
    return 60;
}

const int SnakeGame::getScore() const noexcept
{
    return _score;
}
