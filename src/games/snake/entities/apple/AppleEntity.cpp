/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleEntity
*/

#include "AppleEntity.hpp"

AppleEntity::AppleEntity()
    :   _components()
{
    std::shared_ptr<AppleDisplayable> displayable = std::make_shared<AppleDisplayable>(*this);

    _components.push_back(displayable);
}

AppleEntity::~AppleEntity()
{
}


const shared::games::components::ComponentsMap &AppleEntity::getComponents(void) const noexcept
{
    return _components;
}