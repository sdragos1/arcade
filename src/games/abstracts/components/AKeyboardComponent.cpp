/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AKeyboardComponent
*/

#include "AKeyboardComponent.hpp"

AKeyboardComponent::AKeyboardComponent(entity::IEntity &entity)
    : AComponent(entity, components::ComponentType::KEYBOARD)
{
}

AKeyboardComponent::~AKeyboardComponent()
{
}
