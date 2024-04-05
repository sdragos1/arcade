/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeBodyCollidable
*/

#include "SnakeBodyCollidable.hpp"

SnakeBodyCollidable::SnakeBodyCollidable(const shared::games::entity::IEntity &entity)
    :
    _entity(entity)
{
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

void SnakeBodyCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    (void)target;
}