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
    std::shared_ptr<SnakeHeadDisplayable> displayable =
        std::make_shared<SnakeHeadDisplayable>(*this);
    std::shared_ptr<SnakeHeadKeyboard> keyboard =
        std::make_shared<SnakeHeadKeyboard>(*this);
    std::shared_ptr<SnakeHeadCollidable> collidable =
        std::make_shared<SnakeHeadCollidable>(*this);

    _components.push_back(displayable);
    _components.push_back(keyboard);
    _components.push_back(collidable);
}

SnakeHeadEntity::~SnakeHeadEntity()
{
}

const components::ComponentsMap &SnakeHeadEntity::getComponents(void) const noexcept
{
    return _components;
}
