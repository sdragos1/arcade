/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadKeyboard
*/

#include "SnakeHeadKeyboard.hpp"

SnakeHeadKeyboard::SnakeHeadKeyboard(std::shared_ptr<SnakeHeadDisplayable> entityAdress)
    : _displayable(entityAdress)
{
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
}

void SnakeHeadKeyboard::onKeyPress(std::shared_ptr<IGame> &ctx, shared::graphics::events::IKeyEvent::KeyData key)
{
    (void)ctx;
    std::shared_ptr<entity::IEntity> entity;

    if (_displayable == nullptr)
        return;
    if (key.type != shared::graphics::events::IKeyEvent::KeyType::ARROW)
        return;
    if (key.code.arrow == shared::graphics::events::IKeyEvent::ArrowCode::UP) {
        _displayable->_position.y -= 1;
    } else if (key.code.arrow == shared::graphics::events::IKeyEvent::ArrowCode::DOWN) {
        _displayable->_position.y += 1;
    } else if (key.code.arrow == shared::graphics::events::IKeyEvent::ArrowCode::LEFT) {
        _displayable->_position.x -= 1;
    } else if (key.code.arrow == shared::graphics::events::IKeyEvent::ArrowCode::RIGHT) {
        _displayable->_position.x += 1;
    }
}

void SnakeHeadKeyboard::onKeyRelease(std::shared_ptr<IGame> &ctx, shared::graphics::events::IKeyEvent::KeyData key)
{
    (void)ctx;
    (void)key;
}
