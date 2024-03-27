/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadKeyboard
*/

#include "SnakeHeadKeyboard.hpp"

SnakeHeadKeyboard::SnakeHeadKeyboard(const entity::IEntity &entity)
    :
    _id(),
    _entity(entity)
{
}

SnakeHeadKeyboard::~SnakeHeadKeyboard()
{
}

const components::ComponentType SnakeHeadKeyboard::getType() const noexcept
{
    return components::KEYBOARD;
}

const UUId &SnakeHeadKeyboard::getId() const noexcept
{
    return _id;
}

const entity::IEntity &SnakeHeadKeyboard::getEntity() noexcept
{
    return _entity;
}

void SnakeHeadKeyboard::onKeyPress(std::shared_ptr<IGame> &ctx, components::KeyData key)
{
    (void)ctx;
    std::shared_ptr<SnakeHeadDisplayable> displayable = nullptr;
    for (auto &component : _entity.getComponents()) {
        if (component.second->getType() == components::DISPLAYABLE) {
            displayable = std::dynamic_pointer_cast<SnakeHeadDisplayable>(component.second);
            break;
        }
    }
    if (displayable == nullptr)
        return;
    if (key.type != components::KeyType::ARROW)
        return;
    if (key.code.arrow == components::ArrowCode::UP) {
        displayable->_position.y -= 1;
    } else if (key.code.arrow == components::ArrowCode::DOWN) {
        displayable->_position.y += 1;
    } else if (key.code.arrow == components::ArrowCode::LEFT) {
        displayable->_position.x -= 1;
    } else if (key.code.arrow == components::ArrowCode::RIGHT) {
        displayable->_position.x += 1;
    }
}

void SnakeHeadKeyboard::onKeyRelease(std::shared_ptr<IGame> &ctx, components::KeyData key)
{
    (void)ctx;
    (void)key;
}
