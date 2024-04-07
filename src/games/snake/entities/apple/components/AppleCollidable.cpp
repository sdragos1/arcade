/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleCollidable
*/

#include "AppleCollidable.hpp"

AppleCollidable::AppleCollidable(const shared::games::entity::IEntity &entity)
    : _entity(entity), _position(0, 0), _size(0, 0), _score(0)
{
    for (auto &comp : _entity.getComponents()) {
        if (auto displayable =
            std::dynamic_pointer_cast<shared::games::components::IDisplayableComponent>(comp)) {
            _position = displayable->getPosition();
            _size = displayable->getSize();
            break;
        }
    }
}

AppleCollidable::~AppleCollidable()
{
}

const shared::games::components::ComponentType AppleCollidable::getType() const noexcept
{
    return shared::games::components::ComponentType::COLLIDABLE;
}

const shared::games::entity::IEntity &AppleCollidable::getEntity() noexcept
{
    return _entity;
}

Vector2f &AppleCollidable::getPosition() noexcept
{
    return _position;
}

Vector2u &AppleCollidable::getSize(void) noexcept
{
    return _size;
}

void AppleCollidable::setPosition(Vector2f position) noexcept
{
    _position = position;
}

void AppleCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx,
    std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    if (auto snakeHead = std::dynamic_pointer_cast<SnakeHeadCollidable>(target)) {
        _score += 1;
        setPosition({static_cast<float>(rand() % 32), static_cast<float>(rand() % 18)});
    }
}
