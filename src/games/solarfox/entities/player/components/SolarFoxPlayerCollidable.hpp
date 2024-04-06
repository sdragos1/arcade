/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayerCollidable
*/

#pragma once

#include "../../projectile/components/SolarFoxProjectileCollidable.hpp"
#include "abstracts/components/ACollidableComponent.hpp"

class SolarFoxPlayerCollidable : public ACollidableComponent {
    public:
        SolarFoxPlayerCollidable(shared::types::Vector2f &position, entity::IEntity &entity);
        ~SolarFoxPlayerCollidable();

        void onCollide(std::shared_ptr<IGame> ctx, std::shared_ptr<ICollidableComponent> target);

        bool isDestroyed() const;

    private:
        bool _destroyed;
};
