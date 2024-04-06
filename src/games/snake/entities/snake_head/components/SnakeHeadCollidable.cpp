/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeHeadCollidable
*/

#include "SnakeHeadCollidable.hpp"

SnakeHeadCollidable::SnakeHeadCollidable(const shared::games::entity::IEntity &entity)
    : _entity(entity), _position(0, 0), _size(0, 0)
{
    for (auto &component : _entity.getComponents()) {
        if (auto displayable = std::dynamic_pointer_cast<shared::games::components::IDisplayableComponent>(component)) {
            _position = displayable->getPosition();
            _size = displayable->getSize();
            break;
        }
    }
}

SnakeHeadCollidable::~SnakeHeadCollidable()
{
}

const shared::games::components::ComponentType SnakeHeadCollidable::getType() const noexcept
{
    return shared::games::components::ComponentType::COLLIDABLE;
}

const shared::games::entity::IEntity &SnakeHeadCollidable::getEntity() noexcept
{
    return _entity;
}

Vector2f &SnakeHeadCollidable::getPosition() noexcept
{
    return _position;
}

Vector2u &SnakeHeadCollidable::getSize(void) noexcept
{
    return _size;
}

void SnakeHeadCollidable::setPosition(Vector2f pos) noexcept
{
    _position = pos;
}

void SnakeHeadCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    //does it colide with itself?
}