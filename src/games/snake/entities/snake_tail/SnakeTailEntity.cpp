/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailEntity
*/

#include "SnakeTailEntity.hpp"

SnakeTailEntity::SnakeTailEntity()
    : _components()
{
    std::shared_ptr<SnakeTailDisplayable> displayable =
        std::make_shared<SnakeTailDisplayable>(*this);

    _components.push_back(displayable);
}

SnakeTailEntity::~SnakeTailEntity()
{
}

const components::ComponentsMap &SnakeTailEntity::getComponents(void) const noexcept
{
    return _components;
}