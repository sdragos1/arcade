/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailKeyboard
*/

#include "SnakeTailKeyboard.hpp"

SnakeTailKeyboard::SnakeTailKeyboard(const entity::IEntity &entity)
    :
    _entity(entity)
{
}

SnakeTailKeyboard::~SnakeTailKeyboard()
{
}

const components::ComponentType SnakeTailKeyboard::getType() const noexcept
{
    return components::KEYBOARD;
}

const entity::IEntity &SnakeTailKeyboard::getEntity() noexcept
{
    return _entity;
}

void SnakeTailKeyboard::onKeyPress(std::shared_ptr<IGame> &ctx,  shared::games::components::IKeyboardComponent::KeyData key)
{
    (void)ctx;
    std::shared_ptr<SnakeTailDisplayable> displayable = nullptr;
    for (auto &component : _entity.getComponents()) {
        if (component->getType() == components::ComponentType::TEXTURE) {
            displayable = std::dynamic_pointer_cast<SnakeTailDisplayable>(component);
            break;
        }
    }
    if (displayable == nullptr)
        return;
    if (key.type != shared::games::components::IKeyboardComponent::KeyType::ARROW)
        return;
    if (key.code.arrow == shared::games::components::IKeyboardComponent::ArrowCode::UP) {
        displayable->_position.y -= 1;
    } else if (key.code.arrow ==  shared::games::components::IKeyboardComponent::ArrowCode::DOWN) {
        displayable->_position.y += 1;
    } else if (key.code.arrow ==  shared::games::components::IKeyboardComponent::ArrowCode::LEFT) {
        displayable->_position.x -= 1;
    } else if (key.code.arrow ==  shared::games::components::IKeyboardComponent::ArrowCode::RIGHT) {
        displayable->_position.x += 1;
    }
}

void SnakeTailKeyboard::onKeyRelease(std::shared_ptr<IGame> &ctx, shared::games::components::IKeyboardComponent::KeyData key)
{
    (void)ctx;
    (void)key;
}