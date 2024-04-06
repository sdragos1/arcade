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
    //(void)ctx;
    //auto targetEntity = target->getEntity();
    //auto targetCollidable = targetEntity->getComponents();

    //for (auto &component : targetCollidable) {
    //    if (component->getType() == shared::games::components::ComponentType::COLLIDABLE) {
    //        auto collidable = std::dynamic_pointer_cast<shared::games::components::ICollidableComponent>(component);
    //        std::cout << "Apple collided" << std::endl;
    //    }
    //}
}