/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGame
*/

#include "SnakeGame.hpp"

static int snakeGameScore = 0;
static float maxTop = -1;
static float maxBot = 18;
static float maxLeft = -1;
static float maxRight = 32;

SnakeGame::SnakeGame()
    :   _entities()
{
    _moveSpeed = 75;

    std::shared_ptr<HighScoreTextEntity> highScore = std::make_shared<HighScoreTextEntity>();
    std::shared_ptr<BackgroundEntity> background = std::make_shared<BackgroundEntity>();
    std::shared_ptr<SnakeHeadEntity> head = std::make_shared<SnakeHeadEntity>();
    std::shared_ptr<SnakeBodyEntity> body = std::make_shared<SnakeBodyEntity>(Vector2f(16, 9));
    std::shared_ptr<SnakeBodyEntity> body2 = std::make_shared<SnakeBodyEntity>(Vector2f(15, 9));
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
    _entities.push_back(highScore);
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::compute(DeltaTime dt)
{
    _moveCd += std::chrono::duration_cast<DeltaTime>(std::chrono::milliseconds(static_cast<int>(std::abs(dt.count()))));
    _plusScoreCd += std::chrono::duration_cast<DeltaTime>(std::chrono::milliseconds(static_cast<int>(std::abs(dt.count()))));

    if (_moveCd.count() >= _moveSpeed) {
        moveSnake();
        updatePosition();
        _moveCd = std::chrono::milliseconds(0);
        checkCollisions();
    }

    // to remove
    if (_plusScoreCd.count() >= 5000 && _snakeEntities.size() > 0) {
        snakeGameScore += 1;
        increaseSnakeSize();
        _plusScoreCd = std::chrono::milliseconds(0);
    }
    _moveSpeed = increaseDifficulty(snakeGameScore);
}

void SnakeGame::checkCollisions()
{
    // get the SnakeHeadEntity and AppleEntity from _entities
    // get the collidable components from the entities with getComponents()
    // call the appleCollidable->onCollide() method with the snakeHeadCollidable as the target

    auto headEntity = std::shared_ptr<SnakeHeadEntity>();
    auto appleEntity = std::shared_ptr<AppleEntity>();
    auto snakeHeadCollidable = std::shared_ptr<SnakeHeadCollidable>();
    auto appleCollidable = std::shared_ptr<AppleCollidable>();

    for (auto entity : _entities) {
        if (auto head = std::dynamic_pointer_cast<SnakeHeadEntity>(entity)) {
            headEntity = head;
        }
        if (auto apple = std::dynamic_pointer_cast<AppleEntity>(entity)) {
            appleEntity = apple;
        }
    }
    for (auto component : headEntity->getComponents()) {
        if (auto collidable = std::dynamic_pointer_cast<SnakeHeadCollidable>(component)) {
            snakeHeadCollidable = collidable;
        }
    }
    for (auto component : appleEntity->getComponents()) {
        if (auto collidable = std::dynamic_pointer_cast<AppleCollidable>(component)) {
            appleCollidable = collidable;
        }
    }
    // To FIX
    // appleCollidable->onCollide(NULL, snakeHeadCollidable);
}

const GameManifest &SnakeGame::getManifest() const noexcept
{
    return snakeGameManifest;
}

const Vector2u SnakeGame::getSize(void) const noexcept
{
    return {32, 18};
}

const entity::EntitiesMap &SnakeGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SnakeGame::getFps(void) const noexcept
{
    return 60;
}

const int SnakeGame::getScore() const noexcept
{
    return 0;
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

Vector2f SnakeGame::updateBodyPositions(auto it)
{
    auto head = std::dynamic_pointer_cast<SnakeHeadDisplayable>(*it);
    Vector2f tailNewPosition = {0, 0};
    Vector2f previousPosition = head->getOldPosition();

    auto prevIt = _snakeEntities.begin();
    for (auto it = std::next(_snakeEntities.begin()); it != _snakeEntities.end(); ++it) {
        auto components = it->get()->getComponents();
        for (auto compIt = components.begin(); compIt != components.end(); ++compIt) {
            if (compIt->get()->getType() == components::ComponentType::TEXTURE) {
                if (auto body = std::dynamic_pointer_cast<SnakeBodyDisplayable>(*compIt)) {
                    body->setOldPosition(body->getPosition());
                    tailNewPosition = body->getOldPosition();
                    body->setPosition(previousPosition);
                    previousPosition = tailNewPosition;
                }
            }
        }
        prevIt = it;
    }
    return tailNewPosition;
}

void SnakeGame::updateTailPosition(Vector2f tailNewPosition)
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
                    Vector2f tailNewPosition = updateBodyPositions(it);
                    updateTailPosition(tailNewPosition);
                }
            }
        }
    }
}

void SnakeGame::checkMapExit(std::shared_ptr<SnakeHeadDisplayable> head)
{
    if (head->getPosition().x < maxLeft)
        head->setPosition({maxRight, head->getPosition().y});
    if (head->getPosition().x > maxRight)
        head->setPosition({maxLeft, head->getPosition().y});
    if (head->getPosition().y < maxTop)
        head->setPosition({head->getPosition().x, maxBot});
    if (head->getPosition().y > maxBot)
        head->setPosition({head->getPosition().x, maxTop});
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
        if (directionFound) {
            for (auto componentIt = entityIt->get()->getComponents().begin(); componentIt != entityIt->get()->getComponents().end(); ++componentIt) {
                if (componentIt->get()->getType() == components::ComponentType::TEXTURE) {
                    if (auto head = std::dynamic_pointer_cast<SnakeHeadDisplayable>(*componentIt)) {
                        Vector2f newPosition = head->getPosition();
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
                        checkMapExit(head);
                        break;
                    }
                }
            }
        }
    }
}

void SnakeGame::increaseSnakeSize()
{
    auto tailIt = std::find_if(_snakeEntities.rbegin(), _snakeEntities.rend(), [](const auto& entity) {
        return std::any_of(entity->getComponents().begin(), entity->getComponents().end(), [](const auto& component) {
            return std::dynamic_pointer_cast<SnakeTailDisplayable>(component) != nullptr;
        });
    });
    auto tailEntity = *tailIt;
    auto tailComponent = std::dynamic_pointer_cast<SnakeTailDisplayable>(tailEntity->getComponents().front());

    Vector2f newPosition = tailComponent->getPosition();
    std::shared_ptr<SnakeBodyEntity> newBody = std::make_shared<SnakeBodyEntity>(newPosition);

    auto insertPos = std::next(tailIt).base();
    _snakeEntities.insert(insertPos, newBody);
    _entities.push_back(newBody);
}

int SnakeGame::increaseDifficulty(int score)
{
    if (score >= 5 && score < 10) {
        _moveSpeed = 50;
        return _moveSpeed;
    }
    if (score >= 10 && score < 20) {
        _moveSpeed = 40;
        return _moveSpeed;
    }
    if (score >= 20 && score < 30) {
        _moveSpeed = 30;
        return _moveSpeed;
    }
    if (score >= 40) {
        _moveSpeed = 20;
        return _moveSpeed;
    }
    return _moveSpeed;
}
