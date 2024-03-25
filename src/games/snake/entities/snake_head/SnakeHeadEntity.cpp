/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadEntity
*/

#include "SnakeHeadEntity.hpp"

SnakeHeadEntity::SnakeHeadEntity()
    :
    _id()
    , _components()
{
    std::shared_ptr<SnakeHeadDisplayable> displayable = std::make_shared<SnakeHeadDisplayable>(*this);
    std::shared_ptr<SnakeHeadKeyboard> keyboard = std::make_shared<SnakeHeadKeyboard>(*this);

    _components[displayable->getId()] = displayable;
    _components[keyboard->getId()] = keyboard;
}

SnakeHeadEntity::~SnakeHeadEntity()
{
}

const shared::types::UUId &SnakeHeadEntity::getId(void) const noexcept
{
    return _id;
}

const components::ComponentsMap &SnakeHeadEntity::getComponents(void) const noexcept
{
    return _components;
}
