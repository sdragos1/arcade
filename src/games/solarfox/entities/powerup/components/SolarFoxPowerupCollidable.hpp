/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPowerupCollidable
*/

#pragma once

#include "games/solarfox/entities/projectile/components/SolarFoxProjectileCollidable.hpp"
#include "abstracts/components/ACollidableComponent.hpp"

class SolarFoxPowerupCollidable : public ACollidableComponent {
    public:
        SolarFoxPowerupCollidable(shared::types::Vector2f position, entity::IEntity &entity);
        ~SolarFoxPowerupCollidable();

        void onCollide(std::shared_ptr<IGame> ctx, std::shared_ptr<ICollidableComponent> target);

        bool isDestroyed() const;
    private:
        bool _destroyed;
};
