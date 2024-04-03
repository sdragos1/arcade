/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AComponent
*/

#pragma once

#include "games/components/IComponent.hpp"

using namespace shared::games;

class AComponent {
    public:
        AComponent(entity::IEntity &entity, components::ComponentType type);
        ~AComponent();

        const components::ComponentType getType() const noexcept;
        const entity::IEntity &getEntity() noexcept;

    protected:
        components::ComponentType _type;
        entity::IEntity &_entity;
};
