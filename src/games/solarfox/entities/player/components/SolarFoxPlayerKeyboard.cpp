/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayerKeyboard
*/

#include "SolarFoxPlayerKeyboard.hpp"

SolarFoxPlayerKeyboard::SolarFoxPlayerKeyboard(entity::IEntity &entity)
    : AKeyboardComponent(entity), _lastDirection(components::IKeyboardComponent::ArrowCode::UP)
{
}

SolarFoxPlayerKeyboard::~SolarFoxPlayerKeyboard()
{
}

void SolarFoxPlayerKeyboard::onKeyPress(std::shared_ptr<IGame> ctx,
    components::IKeyboardComponent::KeyData keyData)
{
    (void)ctx;
    std::shared_ptr<TextureComponent> displayable = nullptr;

    for (auto &component : _entity.getComponents()) {
        if (component->getType() == components::TEXTURE) {
            displayable = std::dynamic_pointer_cast<TextureComponent>(component);
            break;
        }
    }
    if (displayable == nullptr)
        return;
    if (keyData.type != components::IKeyboardComponent::KeyType::ARROW)
        return;
    if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::UP &&
        _lastDirection != components::IKeyboardComponent::ArrowCode::DOWN) {
        displayable->getTextureProps().origin.x = 0;
        _lastDirection = components::IKeyboardComponent::ArrowCode::UP;
    } else if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::DOWN &&
        _lastDirection != components::IKeyboardComponent::ArrowCode::UP) {
        displayable->getTextureProps().origin.x = 2;
        _lastDirection = components::IKeyboardComponent::ArrowCode::DOWN;
    } else if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::LEFT &&
        _lastDirection != components::IKeyboardComponent::ArrowCode::RIGHT) {
        displayable->getTextureProps().origin.x = 1;
        _lastDirection = components::IKeyboardComponent::ArrowCode::LEFT;
    } else if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::RIGHT &&
        _lastDirection != components::IKeyboardComponent::ArrowCode::LEFT) {
        displayable->getTextureProps().origin.x = 3;
        _lastDirection = components::IKeyboardComponent::ArrowCode::RIGHT;
    }
}

void SolarFoxPlayerKeyboard::onKeyRelease(std::shared_ptr<IGame> ctx,
    components::IKeyboardComponent::KeyData keyData)
{
    (void)ctx;
    (void)keyData;
}

components::IKeyboardComponent::ArrowCode SolarFoxPlayerKeyboard::getLastDirection() const
{
    return _lastDirection;
}
