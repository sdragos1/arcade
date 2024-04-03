/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ADisplayableComponent
*/

#pragma once

#include "games/components/IDisplayableComponent.hpp"
#include "PositionableComponent.hpp"

class ADisplayableComponent : public components::IDisplayableComponent,
                              public PositionableComponent {
    public:
        ADisplayableComponent(shared::types::Vector2i position,
            shared::types::Vector2u size, entity::IEntity &entity, unsigned int zIndex);
        ~ADisplayableComponent();

        unsigned int &getZIndex() noexcept override;

    protected:
        unsigned int _zIndex;
};
