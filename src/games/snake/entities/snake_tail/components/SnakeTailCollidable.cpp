/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeTailCollidable
*/

#include "SnakeTailCollidable.hpp"

SnakeTailCollidable::SnakeTailCollidable(shared::games::entity::IEntity &entity)
    : shared::games::components::ICollidableComponent(entity)
{
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

void SnakeTailCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    (void)target;
}
