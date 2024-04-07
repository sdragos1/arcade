/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGame
*/

#include "SnakeGame.hpp"

static unsigned int snakeBodyIdCounter = 3;
static float maxTop = 0;
static float maxBot = 18;
static float maxLeft = 0;
static float maxRight = 32;

SnakeGame::SnakeGame()
    :   _entities(), _snakeEntities()
{
    gameInit();
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::gameInit()
{
    _moveSpeed = 75;
    _prevScore = 0;
    _snakeEntities.clear();
    _entities.clear();

    std::shared_ptr<BackgroundEntity> background = std::make_shared<BackgroundEntity>();
    std::shared_ptr<SnakeHeadEntity> head = std::make_shared<SnakeHeadEntity>();
    std::shared_ptr<SnakeBodyEntity> body = std::make_shared<SnakeBodyEntity>(Vector2f(16, 9), 1);
    std::shared_ptr<SnakeBodyEntity> body2 = std::make_shared<SnakeBodyEntity>(Vector2f(15, 9), 2);
    std::shared_ptr<SnakeTailEntity> tail = std::make_shared<SnakeTailEntity>();
    std::shared_ptr<AppleEntity> apple = std::make_shared<AppleEntity>();
    std::shared_ptr<ScoreTextEntity> score = std::make_shared<ScoreTextEntity>();
    _snakeEntities.push_back(head);
    _snakeEntities.push_back(body);
    _snakeEntities.push_back(body2);
    _snakeEntities.push_back(tail);
    _entities.push_back(background);
    _entities.push_back(apple);
    _entities.push_back(head);
    _entities.push_back(body);
    _entities.push_back(body2);
    _entities.push_back(tail);
    _entities.push_back(score);
}

void SnakeGame::compute(DeltaTime dt)
{
    if (dt == DeltaTime::zero()) {
        _moveCd += DeltaTime(1);
    } else {
        _moveCd += std::chrono::duration_cast<DeltaTime>(std::chrono::milliseconds
            (static_cast<int>(std::abs(dt.count()))));
    }

    if (_moveSpeed > 0) {
        if (_moveCd.count() >= _moveSpeed) {
            moveSnake();
            updatePosition();
            _moveCd = std::chrono::milliseconds(0);
        }
    }
    if (getScore() == (_prevScore + 1)) {
        increaseSnakeSize();
        _prevScore = getScore();
        for (auto it = _entities.begin(); it != _entities.end(); ++it) {
            if (auto scoreEntity = std::dynamic_pointer_cast<ScoreTextEntity>(*it)) {
                // scoreEntity->updateScore(getScore());
            }
        }
        updateApplePosition();
    }
    _moveSpeed = increaseDifficulty(getScore());
    if (checkLose() == true) {
        _moveSpeed = 0;
        gameInit();
    }
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
    for (auto it = _entities.begin(); it != _entities.end(); ++it) {
        for (auto compIt = it->get()->getComponents().begin(); compIt !=
            it->get()->getComponents().end(); ++compIt) {
            if (compIt->get()->getType() == components::ComponentType::COLLIDABLE) {
                if (auto apple = std::dynamic_pointer_cast<AppleCollidable>(*compIt)) {
                    return apple->_score;
                }
            }
        }
    }
    return 0;
}

bool SnakeGame::checkLose(void)
{
    for (auto it = _snakeEntities.begin(); it != _snakeEntities.end(); ++it) {
        for (auto compIt = it->get()->getComponents().begin(); compIt !=
            it->get()->getComponents().end(); ++compIt) {
            if (compIt->get()->getType() == components::ComponentType::COLLIDABLE) {
                if (auto head = std::dynamic_pointer_cast<SnakeHeadCollidable>(*compIt)) {
                    return head->getLose();
                }
            }
        }
    }
    return false;
}

void SnakeGame::updateApplePosition()
{
    Vector2f newApplePosition = {0, 0};

    for (auto appleEntity = _entities.begin(); appleEntity != _entities.end(); ++appleEntity) {
        for (auto appleComp = appleEntity->get()->getComponents().begin(); appleComp !=
            appleEntity->get()->getComponents().end(); ++appleComp) {
            if (appleComp->get()->getType() == components::ComponentType::COLLIDABLE) {
                if (auto apple = std::dynamic_pointer_cast<AppleCollidable>(*appleComp)) {
                    newApplePosition = apple->getPosition();
                    break;
                }
            }
        }
    }
    for (auto appleEntity = _entities.begin(); appleEntity != _entities.end(); ++appleEntity) {
        for (auto appleComp = appleEntity->get()->getComponents().begin(); appleComp !=
            appleEntity->get()->getComponents().end(); ++appleComp) {
            if (appleComp->get()->getType() == components::ComponentType::TEXTURE) {
                if (auto apple = std::dynamic_pointer_cast<AppleDisplayable>(*appleComp)) {
                    apple->_position = newApplePosition;
                }
            }
        }
    }
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

void SnakeGame::updateBodyCollidablePosition(auto it, Vector2f previousPosition)
{
    if (auto body = std::dynamic_pointer_cast<SnakeBodyCollidable>(*it)) {
        body->setPosition(previousPosition);
    }
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
            if (compIt->get()->getType() == components::ComponentType::COLLIDABLE) {
                updateBodyCollidablePosition(compIt, previousPosition);
            }
        }
        prevIt = it;
    }
    return tailNewPosition;
}

void SnakeGame::updateTailCollidablePosition(auto it, Vector2f pos)
{
    if (auto tail = std::dynamic_pointer_cast<SnakeTailCollidable>(*it)) {
        tail->setPosition(pos);
    }
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
            if (it->get()->getType() == components::ComponentType::COLLIDABLE) {
                updateTailCollidablePosition(it, tailNewPosition);
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

bool SnakeGame::findDirection(auto it)
{
    bool directionFound = false;

    for (auto componentIt = it->get()->getComponents().begin(); componentIt !=
        it->get()->getComponents().end(); ++componentIt) {
        if (componentIt->get()->getType() == components::ComponentType::KEYBOARD) {
            if (auto keyboard = std::dynamic_pointer_cast<SnakeHeadKeyboard>(*componentIt)) {
                _direction = keyboard->_direction;
                directionFound = true;
                return directionFound;
            }
        }
    }
    return directionFound;
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

Vector2f SnakeGame::updateHeadPosition(auto it)
{
    if (auto head = std::dynamic_pointer_cast<SnakeHeadDisplayable>(*it)) {
        Vector2f newPosition = head->getPosition();
        switch (_direction) {
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
        return newPosition;
    }
    return {0, 0};
}

void SnakeGame::updateHeadCollidablePosition(auto it, Vector2f newPosition)
{
    if (auto head = std::dynamic_pointer_cast<SnakeHeadCollidable>(*it)) {
        head->setPosition(newPosition);
    }
}

void SnakeGame::moveSnake()
{
    Vector2f newPosition = {0, 0};

    for (auto entityIt = _snakeEntities.begin(); entityIt != _snakeEntities.end(); ++entityIt) {
        if (findDirection(entityIt) == true) {
            for (auto componentIt = entityIt->get()->getComponents().begin(); componentIt !=
                entityIt->get()->getComponents().end(); ++componentIt) {
                if (componentIt->get()->getType() == components::ComponentType::TEXTURE) {
                    newPosition = updateHeadPosition(componentIt);
                }
                if (componentIt->get()->getType() == components::ComponentType::COLLIDABLE) {
                    updateHeadCollidablePosition(componentIt, newPosition);
                }
            }
        }
    }
}

void SnakeGame::increaseSnakeSize()
{
    auto tailIt = std::find_if(_snakeEntities.rbegin(), _snakeEntities.rend(),
        [](const auto& entity) { return std::any_of(entity->getComponents().begin(),
            entity->getComponents().end(), [](const auto& component) {
            return std::dynamic_pointer_cast<SnakeTailDisplayable>(component) != nullptr;
        });
    });
    auto tailEntity = *tailIt;
    auto tailComponent = std::dynamic_pointer_cast<SnakeTailDisplayable>(
        tailEntity->getComponents().front());

    Vector2f newPosition = tailComponent->getPosition();
    std::shared_ptr<SnakeBodyEntity> newBody = std::make_shared<SnakeBodyEntity>(
        newPosition, snakeBodyIdCounter);
    snakeBodyIdCounter++;

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
