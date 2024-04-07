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
<<<<<<< HEAD
    _components.push_back(displayable);
    std::shared_ptr<SnakeTailCollidable> collidable =
        std::make_shared<SnakeTailCollidable>(*this);
    _components.push_back(collidable);
=======
    std::shared_ptr<SnakeTailKeyboard> keyboard =
        std::make_shared<SnakeTailKeyboard>(*this);

    _components.push_back(displayable);
    _components.push_back(keyboard);
>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)
}

SnakeTailEntity::~SnakeTailEntity()
{
}

const components::ComponentsMap &SnakeTailEntity::getComponents(void) const noexcept
{
    return _components;
<<<<<<< HEAD
}
=======
}
>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)
