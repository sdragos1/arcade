/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AKeyboardComponent
*/

#pragma once

#include "games/components/IKeyboardComponent.hpp"
#include "AComponent.hpp"

using namespace shared::games;

class AKeyboardComponent : public components::IKeyboardComponent,
                           public AComponent {
    public:
        AKeyboardComponent(entity::IEntity &entity);
        ~AKeyboardComponent();
};
