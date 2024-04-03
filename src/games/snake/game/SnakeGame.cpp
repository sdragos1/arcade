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
    std::shared_ptr<BackgroundEntity> background = std::make_shared<BackgroundEntity>();
    std::shared_ptr<SnakeHeadEntity> head = std::make_shared<SnakeHeadEntity>();
    std::shared_ptr<SnakeBodyEntity> body = std::make_shared<SnakeBodyEntity>(Vector2i(1, 0));
    std::shared_ptr<SnakeBodyEntity> body2 = std::make_shared<SnakeBodyEntity>(Vector2i(2, 0));
    std::shared_ptr<SnakeTailEntity> tail = std::make_shared<SnakeTailEntity>();
    std::shared_ptr<AppleEntity> apple = std::make_shared<AppleEntity>();
    std::shared_ptr<ScoreTextEntity> score = std::make_shared<ScoreTextEntity>();
    _snakeEntities.push_back(head);
    _snakeEntities.push_back(body);
    _snakeEntities.push_back(body2);
    _snakeEntities.push_back(tail);
    _entities.push_back(background);
    _entities.push_back(head);
    _entities.push_back(body);
    _entities.push_back(body2);
    _entities.push_back(tail);
    _entities.push_back(apple);
    _entities.push_back(score);
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::compute(DeltaTime dt)
{
    _moveCd += std::chrono::duration_cast<DeltaTime>(std::chrono::milliseconds(static_cast<int>(std::abs(dt.count()))));


    if (_moveCd.count() >= 30) {
        moveSnake();
        updatePosition();
        _moveCd -= std::chrono::milliseconds(30);
    }
}

const GameManifest &SnakeGame::getManifest() const noexcept
{
    return snakeGameManifest;
}

const Vector2u SnakeGame::getSize(void) const noexcept
{
    return {1280, 720};
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
    Vector2i previousPosition = head->getOldPosition();

    auto prevIt = _snakeEntities.begin();
    for (auto it = std::next(_snakeEntities.begin()); it != _snakeEntities.end(); ++it) {
        auto components = it->get()->getComponents();
        for (auto compIt = components.begin(); compIt != components.end(); ++compIt) {
            if (compIt->get()->getType() == components::ComponentType::TEXTURE) {
                if (auto body = std::dynamic_pointer_cast<SnakeBodyDisplayable>(*compIt)) {
                    tailNewPosition = body->getOldPosition();
                    body->setOldPosition(body->getPosition());
                    body->setPosition(previousPosition);
                    previousPosition = tailNewPosition;
                }
            }
        }
        prevIt = it;
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

void SnakeGame::updatePosition()
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

void SnakeGame::moveSnake()
{
    for (auto entityIt = _snakeEntities.begin(); entityIt != _snakeEntities.end(); ++entityIt) {
        SnakeHeadKeyboard::Direction direction;
        bool directionFound = false;
        for (auto componentIt = entityIt->get()->getComponents().begin(); componentIt != entityIt->get()->getComponents().end(); ++componentIt) {
            if (componentIt->get()->getType() == components::ComponentType::KEYBOARD) {
                if (auto keyboard = std::dynamic_pointer_cast<SnakeHeadKeyboard>(*componentIt)) {
                    direction = keyboard->_direction;
                    directionFound = true;
                    break;
                }
            }
        }
        std::cout << "Direction: " << direction << std::endl;
        if (directionFound) {
            for (auto componentIt = entityIt->get()->getComponents().begin(); componentIt != entityIt->get()->getComponents().end(); ++componentIt) {
                if (componentIt->get()->getType() == components::ComponentType::TEXTURE) {
                    if (auto head = std::dynamic_pointer_cast<SnakeHeadDisplayable>(*componentIt)) {
                        Vector2i newPosition = head->getPosition();
                        switch (direction) {
                            case SnakeHeadKeyboard::UP:
                                newPosition.y -= 1;
                                break;
                            case SnakeHeadKeyboard::DOWN:
                                newPosition.y += 1;
                                break;
                            case SnakeHeadKeyboard::LEFT:
                                newPosition.x -= 1;
                                break;
                            case SnakeHeadKeyboard::RIGHT:
                                newPosition.x += 1;
                                break;
                        }
                        head->setOldPosition(head->getPosition());
                        head->setPosition(newPosition);
                        break;
                    }
                }
            }
        }
    }
}