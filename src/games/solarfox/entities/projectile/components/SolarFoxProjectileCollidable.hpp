/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProjectileCollidable
*/

#pragma once

#include "../Projectile.hpp"
#include "abstracts/components/ACollidableComponent.hpp"

class SolarFoxProjectileCollidable : public ACollidableComponent {
    public:
        SolarFoxProjectileCollidable(shared::types::Vector2f &position, entity::IEntity &entity,
            ProjectileType type);
        ~SolarFoxProjectileCollidable();

        void onCollide(std::shared_ptr<IGame> ctx, std::shared_ptr<ICollidableComponent> target);

        bool isDestroyed() const;
        ProjectileType getProjectileType() const;

    private:
        bool _destroyed;
        ProjectileType _type;
};
