/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeTailCollidable
*/

#include <iostream>

#include "SnakeTailCollidable.hpp"

SnakeTailCollidable::SnakeTailCollidable(const shared::games::entity::IEntity &entity)
    : _entity(entity), _position(0, 0), _size(0, 0)
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

SnakeTailCollidable::~SnakeTailCollidable()
{
}

const shared::games::components::ComponentType SnakeTailCollidable::getType() const noexcept
{
    return shared::games::components::ComponentType::COLLIDABLE;
}

const shared::games::entity::IEntity &SnakeTailCollidable::getEntity() noexcept
{
    return _entity;
}

Vector2f &SnakeTailCollidable::getPosition(void) noexcept
{
    return _position;
}

Vector2u &SnakeTailCollidable::getSize(void) noexcept
{
    return _size;
}

void SnakeTailCollidable::setPosition(Vector2f pos) noexcept
{
    _position = pos;
}

void SnakeTailCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx,
    std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    (void)target;
}
