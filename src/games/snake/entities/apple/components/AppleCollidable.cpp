/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleCollidable
*/

#include "AppleCollidable.hpp"

AppleCollidable::AppleCollidable(shared::games::entity::IEntity &entity)
    : shared::games::components::ICollidableComponent(entity)
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
    (void)ctx;
    (void)target;
}