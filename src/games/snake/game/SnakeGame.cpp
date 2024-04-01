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
    moveSnake();
}

const GameManifest &SnakeGame::getManifest() const noexcept
{
    return snakeGameManifest;
}

const Vector2u SnakeGame::getSize(void) const noexcept
{
    return {1920, 1080};
}

const entity::EntitiesMap &SnakeGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SnakeGame::getFps(void) const noexcept
{
    return 60;
}

bool SnakeGame::hasHeadMoved(auto it)
{
    if (auto head = std::dynamic_pointer_cast<SnakeHeadDisplayable>(*it)) {
        if (head.get()->getOldPosition().x != head.get()->getPosition().x ||
            head.get()->getOldPosition().y != head.get()->getPosition().y) {
            return true;
        }
    }
    return false;
}

Vector2i SnakeGame::updateBodyPositions(auto it)
{
    auto head = std::dynamic_pointer_cast<SnakeHeadDisplayable>(*it);
    Vector2i tailNewPosition = {0, 0};

    for (auto it = _snakeEntities.begin(); it != _snakeEntities.end(); ++it) {
        if (next(it) == _snakeEntities.end())
            break;
        auto components = it->get()->getComponents();
        for (auto it = components.begin(); it != components.end(); ++it) {
            if (it->get()->getType() == components::ComponentType::TEXTURE) {
                if (auto body = std::dynamic_pointer_cast<SnakeBodyDisplayable>(*it)) {
                    tailNewPosition = body.get()->getOldPosition();
                    body.get()->setOldPosition(body.get()->getPosition());
                    body.get()->setPosition(head.get()->getOldPosition());
                }
            }
        }
    }
    return tailNewPosition;
}

void SnakeGame::updateTailPosition(Vector2i tailNewPosition)
{
    for (auto it = _snakeEntities.begin(); it != _snakeEntities.end(); ++it) {
        auto components = it->get()->getComponents();
        for (auto it = components.begin(); it != components.end(); ++it) {
            if (it->get()->getType() == components::ComponentType::TEXTURE) {
                if (auto tail = std::dynamic_pointer_cast<SnakeTailDisplayable>(*it)) {
                    tail.get()->setPosition(tailNewPosition);
                }
            }
        }
    }
}

void SnakeGame::moveSnake()
{
    auto it = _snakeEntities.begin();
    auto components = it->get()->getComponents();

    for (auto it = _snakeEntities.begin(); it != _snakeEntities.end(); ++it) {
        auto components = it->get()->getComponents();
        for (auto it = components.begin(); it != components.end(); ++it) {
            if (it->get()->getType() == components::ComponentType::TEXTURE) {
                if (hasHeadMoved(it) == true) {
                    Vector2i tailNewPosition = updateBodyPositions(it);
                    updateTailPosition(tailNewPosition);
                }
            }
        }
    }
}
