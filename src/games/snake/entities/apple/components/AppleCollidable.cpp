/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleCollidable
*/

#include "AppleCollidable.hpp"
#include <iostream>

AppleCollidable::AppleCollidable(const shared::games::entity::IEntity &entity)
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

void AppleCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    std::cout << "Apple collided" << std::endl;
}