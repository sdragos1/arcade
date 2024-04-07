/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyKeyboard
*/

#include "SnakeBodyKeyboard.hpp"

SnakeBodyKeyboard::SnakeBodyKeyboard(const entity::IEntity &entity)
    :
    _entity(entity)
{
}

SnakeBodyKeyboard::~SnakeBodyKeyboard()
{
}

const components::ComponentType SnakeBodyKeyboard::getType() const noexcept
{
    return components::KEYBOARD;
}

const entity::IEntity &SnakeBodyKeyboard::getEntity() noexcept
{
    return _entity;
}

void SnakeBodyKeyboard::onKeyPress(std::shared_ptr<IGame> &ctx, components::KeyData key)
{
    (void)ctx;
    std::shared_ptr<SnakeBodyKeyboard> displayable = nullptr;
    for (auto &component : _entity.getComponents()) {
        if (component->getType() == components::ComponentType::TEXTURE) {
            displayable = std::dynamic_pointer_cast<SnakeBodyKeyboard>(component);
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

void SnakeBodyKeyboard::onKeyRelease(std::shared_ptr<IGame> &ctx, components::KeyData key)
{
    (void)ctx;
    (void)key;
}