/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadKeyboard
*/

#include "SnakeHeadKeyboard.hpp"
#include <iostream>

SnakeHeadKeyboard::SnakeHeadKeyboard(const entity::IEntity &entity)
    :
    _entity(entity)
{
    _direction = RIGHT;
}

SnakeHeadKeyboard::~SnakeHeadKeyboard()
{
}

const components::ComponentType SnakeHeadKeyboard::getType() const noexcept
{
    return components::KEYBOARD;
}

const entity::IEntity &SnakeHeadKeyboard::getEntity() noexcept
{
    return _entity;
}

void SnakeHeadKeyboard::onKeyPress(std::shared_ptr<IGame> ctx, shared::games::components::IKeyboardComponent::KeyData key)
{
    (void)ctx;
    std::shared_ptr<SnakeHeadDisplayable> displayable = nullptr;
    for (auto &component : _entity.getComponents()) {
        if (component->getType() == components::ComponentType::TEXTURE) {
            displayable = std::dynamic_pointer_cast<SnakeHeadDisplayable>(component);
            break;
        }
    }
    if (key.type != shared::games::components::IKeyboardComponent::KeyType::ARROW)
        return;
    if (key.code.arrow == shared::games::components::IKeyboardComponent::ArrowCode::UP) {
        if (_direction == DOWN)
            return;
        displayable->_oldPosition = displayable->_position;
        displayable->_textureProps.origin = {1, 0};
        _direction = UP;
    } else if (key.code.arrow ==  shared::games::components::IKeyboardComponent::ArrowCode::DOWN) {
        if (_direction == UP)
            return;
        displayable->_oldPosition = displayable->_position;
        displayable->_textureProps.origin = {0, 0};
        _direction = DOWN;
    } else if (key.code.arrow ==  shared::games::components::IKeyboardComponent::ArrowCode::LEFT) {
        if (_direction == RIGHT)
            return;
        displayable->_oldPosition = displayable->_position;
        displayable->_textureProps.origin = {2, 0};
        _direction = LEFT;
    } else if (key.code.arrow ==  shared::games::components::IKeyboardComponent::ArrowCode::RIGHT) {
        if (_direction == LEFT)
            return;
        displayable->_oldPosition = displayable->_position;
        displayable->_textureProps.origin = {3, 0};
        _direction = RIGHT;
    }
}

void SnakeHeadKeyboard::onKeyRelease(std::shared_ptr<IGame> ctx, shared::games::components::IKeyboardComponent::KeyData key)
{
    (void)ctx;
    (void)key;
}