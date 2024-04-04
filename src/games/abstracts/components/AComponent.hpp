/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AComponent
*/

#pragma once

#include "games/components/IComponent.hpp"

using namespace shared::games;

class AComponent : public virtual components::IComponent {
    public:
        AComponent(entity::IEntity &entity, components::ComponentType type);
        ~AComponent();

        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

    protected:
        components::ComponentType _type;
        entity::IEntity &_entity;
};
