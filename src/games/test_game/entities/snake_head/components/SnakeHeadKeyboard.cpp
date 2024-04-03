/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadKeyboard
*/

#include <iostream>
#include "SnakeHeadKeyboard.hpp"

SnakeHeadKeyboard::SnakeHeadKeyboard(const entity::IEntity &entity)
    : _entity(entity)
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
    return _entity;
}

void SnakeHeadKeyboard::onKeyPress(std::shared_ptr<IGame> ctx,
    shared::games::components::IKeyboardComponent::KeyData key)
{
    (void)ctx;
    std::shared_ptr<SnakeHeadDisplayable> displayable = nullptr;
    std::shared_ptr<ASoundComponent> sound = nullptr;

    for (auto &component : _entity.getComponents()) {
        if (component->getType() == components::TEXTURE) {
            displayable = std::dynamic_pointer_cast<SnakeHeadDisplayable>(component);
        }
        if (component->getType() == components::SOUND) {
            sound = std::dynamic_pointer_cast<ASoundComponent>(component);
        }
    }
    if (displayable == nullptr)
        return;
    if (key.type != shared::games::components::IKeyboardComponent::KeyType::ARROW) {
        return;
    } else {
        if (sound != nullptr) {
            sound->getState() = shared::games::components::SoundState::PLAY;
        }
    }
    if (key.code.arrow == shared::games::components::IKeyboardComponent::ArrowCode::UP) {
        displayable->_position.y -= 1;
    } else if (key.code.arrow == shared::games::components::IKeyboardComponent::ArrowCode::DOWN) {
        displayable->_position.y += 1;
    } else if (key.code.arrow == shared::games::components::IKeyboardComponent::ArrowCode::LEFT) {
        displayable->_position.x -= 1;
    } else if (key.code.arrow == shared::games::components::IKeyboardComponent::ArrowCode::RIGHT) {
        displayable->_position.x += 1;
    }
}

void SnakeHeadKeyboard::onKeyRelease(std::shared_ptr<IGame> ctx,
    shared::games::components::IKeyboardComponent::KeyData key)
{
    (void)ctx;
    (void)key;
}
