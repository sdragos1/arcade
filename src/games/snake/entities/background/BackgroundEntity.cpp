/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** BackgroundEntity
*/

#include "BackgroundEntity.hpp"

BackgroundEntity::BackgroundEntity()
    :   _components()
{
    std::shared_ptr<BackgroundDisplayable> displayable =
        std::make_shared<BackgroundDisplayable>(*this);

    _components.push_back(displayable);
}

BackgroundEntity::~BackgroundEntity()
{
}


const shared::games::components::ComponentsMap &BackgroundEntity::getComponents(
    void) const noexcept
{
    return _components;
}
