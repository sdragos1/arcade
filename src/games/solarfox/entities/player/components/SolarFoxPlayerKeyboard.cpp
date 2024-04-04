/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayerKeyboard
*/

#include "SolarFoxPlayerKeyboard.hpp"

SolarFoxPlayerKeyboard::SolarFoxPlayerKeyboard(entity::IEntity &entity)
    : AKeyboardComponent(entity)
{
}

SolarFoxPlayerKeyboard::~SolarFoxPlayerKeyboard()
{
}

void SolarFoxPlayerKeyboard::onKeyPress(std::shared_ptr<IGame> ctx, components::IKeyboardComponent::KeyData keyData)
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
    if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::UP) {
        displayable->getPosition().y -= 1;
        displayable->getTextureProps().origin.x = 0;
    } else if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::DOWN) {
        displayable->getPosition().y += 1;
        displayable->getTextureProps().origin.x = 2;
    } else if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::LEFT) {
        displayable->getPosition().x -= 1;
        displayable->getTextureProps().origin.x = 1;
    } else if (keyData.code.arrow == components::IKeyboardComponent::ArrowCode::RIGHT) {
        displayable->getPosition().x += 1;
        displayable->getTextureProps().origin.x = 3;
    }
}

void SolarFoxPlayerKeyboard::onKeyRelease(std::shared_ptr<IGame> ctx,
    components::IKeyboardComponent::KeyData keyData)
{
    (void)ctx;
    (void)keyData;
}
