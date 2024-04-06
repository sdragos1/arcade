/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleCollidable
*/

#include "AppleCollidable.hpp"
#include <iostream>

AppleCollidable::AppleCollidable(const shared::games::entity::IEntity &entity)
    :
    _entity(entity)
{
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

void AppleCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    for (auto &component : _entity.getComponents()) {
        if (auto displayable = std::dynamic_pointer_cast<AppleDisplayable>(component)) {
            displayable->_position = {static_cast<float>(rand() % 32), static_cast<float>(rand() % 18)};
            break;
        }
    }
}