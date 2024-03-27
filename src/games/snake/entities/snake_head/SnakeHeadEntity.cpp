/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadEntity
*/

#include "SnakeHeadEntity.hpp"

SnakeHeadEntity::SnakeHeadEntity()
    : _components()
{
    std::shared_ptr<components::IComponent> displayable = std::make_shared<SnakeHeadDisplayable>(*this);
    _components.push_back(displayable);
    _components.push_back(std::make_shared<SnakeHeadKeyboard>(std::dynamic_pointer_cast<SnakeHeadDisplayable>(displayable)));
}

SnakeHeadEntity::~SnakeHeadEntity()
{
}

const components::ComponentsMap &SnakeHeadEntity::getComponents(void) const noexcept
{
    return _components;
}
