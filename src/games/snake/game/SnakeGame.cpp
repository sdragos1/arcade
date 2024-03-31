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
    std::shared_ptr<SnakeHeadEntity> head = std::make_shared<SnakeHeadEntity>();
    std::shared_ptr<SnakeBodyEntity> body = std::make_shared<SnakeBodyEntity>();
    std::shared_ptr<SnakeTailEntity> tail = std::make_shared<SnakeTailEntity>();
    std::shared_ptr<AppleEntity> apple = std::make_shared<AppleEntity>();
    std::shared_ptr<ScoreTextEntity> score = std::make_shared<ScoreTextEntity>();
    _snakeEntities.push_back(head);
    _snakeEntities.push_back(body);
    _snakeEntities.push_back(tail);
    _entities.push_back(head);
    _entities.push_back(body);
    _entities.push_back(tail);
    _entities.push_back(apple);
    _entities.push_back(score);
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::compute(DeltaTime dt)
{
    (void)dt;
    std::cout << "SnakeGame::compute" << std::endl;
    moveSnake();
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

void SnakeGame::moveSnake()
{
    // move the snake elements from the list to make it follow the snake like in the snake game
    // look at the head position and move the body and tail following the head position
    // the second part of the body goes to the old position of the first part of the body etc etc
    // check in the list if the snake's head position was updated or not
    // if the head has changed position, all the elements in the list are set to the position of the element above it in the list
    Vector2i previousPosition(0, 0);

    auto it = _snakeEntities.begin();
    if (auto head = std::dynamic_pointer_cast<SnakeBodyDisplayable>(*it)) {
        previousPosition = head->getPosition();
    }
    ++it;
    for (; it != _snakeEntities.end(); ++it) {
        if (auto bodyPart = std::dynamic_pointer_cast<SnakeBodyDisplayable>(*it)) {
            Vector2i currentPosition = bodyPart->getPosition();
            bodyPart->setPosition(previousPosition);
            previousPosition = currentPosition;
        }
    }
}