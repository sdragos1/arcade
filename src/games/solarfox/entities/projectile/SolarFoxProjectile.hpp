/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProjectile
*/

#pragma once

#include <iostream>
#include "abstracts/components/TextureComponent.hpp"
#include "components/SolarFoxProjectileCollidable.hpp"
#include "abstracts/entity/AEntity.hpp"
#include "types/Vector.hpp"
#include "Projectile.hpp"

using namespace shared::games;

class SolarFoxProjectile : public AEntity {
    public:
        SolarFoxProjectile(ProjectileType type,
            shared::types::Vector2f position,
            shared::types::Vector2f direction);
        ~SolarFoxProjectile();

        shared::types::Vector2f &getDirection();
        shared::types::Vector2f &getPosition();
        shared::types::Vector2f &getStartingPosition();
        const ProjectileType getType() const;
        void moveProjectile();
        unsigned int getProjectileTravelDistance();
        bool isDestroyed() const;

    private:
        shared::types::Vector2u _getOriginFromDirection();

        ProjectileType _type;
        shared::types::Vector2f _direction;
        shared::types::Vector2f _position;
        shared::types::Vector2f _startingPosition;
        components::TextureProps _textureProps;
};

static components::TextureProps SolarFoxEnemyProjectileTextureProps = {
    .sources = {
        .ascii = "assets/games/solarfox/projectiles/enemy_projectile.ascii",
        .bin = "assets/games/solarfox/projectiles/enemy_projectile.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};

static components::TextureProps SolarFoxPlayerProjectileTextureProps = {
    .sources = {
        .ascii = "assets/games/solarfox/projectiles/player_beam_sheet.ascii",
        .bin = "assets/games/solarfox/projectiles/player_beam_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};
