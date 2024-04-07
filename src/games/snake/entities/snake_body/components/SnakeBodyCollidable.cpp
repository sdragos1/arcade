/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeBodyCollidable
*/

#include "SnakeBodyCollidable.hpp"

SnakeBodyCollidable::SnakeBodyCollidable(const shared::games::entity::IEntity &entity, unsigned int id)
    : _entity(entity), _position(0, 0), _size(0, 0), _id(id)
{
    for (auto &component : _entity.getComponents()) {
        if (auto displayable = std::dynamic_pointer_cast<shared::games::components::IDisplayableComponent>(component)) {
            _position = displayable->getPosition();
            _size = displayable->getSize();
            break;
        }
    }
}

SnakeBodyCollidable::~SnakeBodyCollidable()
{
}

const shared::games::components::ComponentType SnakeBodyCollidable::getType() const noexcept
{
    return shared::games::components::ComponentType::COLLIDABLE;
}

const shared::games::entity::IEntity &SnakeBodyCollidable::getEntity() noexcept
{
    return _entity;
}

Vector2f &SnakeBodyCollidable::getPosition() noexcept
{
    return _position;
}

Vector2u &SnakeBodyCollidable::getSize(void) noexcept
{
    return _size;
}

unsigned int SnakeBodyCollidable::getId(void) noexcept
{
    return _id;
}

void SnakeBodyCollidable::setPosition(Vector2f pos) noexcept
{
    _position = pos;
}

void SnakeBodyCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    (void)target;
}