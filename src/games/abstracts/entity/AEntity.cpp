/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AEntity
*/

#include "AEntity.hpp"

AEntity::AEntity()
    : _components()
{
}

AEntity::~AEntity()
{
}

const shared::games::components::ComponentsMap &AEntity::getComponents(void) const noexcept
{
    return _components;
}
