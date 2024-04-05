/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeHeadCollidable
*/

#include "SnakeHeadCollidable.hpp"

SnakeHeadCollidable::SnakeHeadCollidable(const shared::games::entity::IEntity &entity)
    :
    _entity(entity)
{
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

void SnakeHeadCollidable::onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target)
{
    (void)ctx;
    (void)target;
}
