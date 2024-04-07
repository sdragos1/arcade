/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyEntity
*/

#include "SnakeBodyEntity.hpp"

SnakeBodyEntity::SnakeBodyEntity(Vector2f position, unsigned int id)
    : _components(), _id(id)
{
    std::shared_ptr<SnakeBodyDisplayable> displayable = std::make_shared<SnakeBodyDisplayable>(*this, position);
    _components.push_back(displayable);
    std::shared_ptr<SnakeBodyCollidable> collidable = std::make_shared<SnakeBodyCollidable>(*this, id);
    _components.push_back(collidable);
}

SnakeBodyEntity::~SnakeBodyEntity()
{
}

const components::ComponentsMap &SnakeBodyEntity::getComponents(void) const noexcept
{
    return _components;
}