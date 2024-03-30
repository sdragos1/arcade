/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyEntity
*/

#include "SnakeBodyEntity.hpp"

SnakeBodyEntity::SnakeBodyEntity()
    : _components()
{
    std::shared_ptr<SnakeBodyDisplayable> displayable =
        std::make_shared<SnakeBodyDisplayable>(*this);

    _components.push_back(displayable);
}

SnakeBodyEntity::~SnakeBodyEntity()
{
}

const components::ComponentsMap &SnakeBodyEntity::getComponents(void) const noexcept
{
    return _components;
}