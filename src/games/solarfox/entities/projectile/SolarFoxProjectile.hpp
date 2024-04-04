/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProjectile
*/

#pragma once

#include <iostream>
#include "abstracts/components/TextureComponent.hpp"
#include "abstracts/entity/AEntity.hpp"
#include "types/Vector.hpp"

using namespace shared::games;

class SolarFoxProjectile : public AEntity {
    public:
        typedef enum {
            PLAYER,
            ENEMY
        } ProjectileType;

        SolarFoxProjectile(ProjectileType type,
            shared::types::Vector2i position,
            shared::types::Vector2i direction);
        ~SolarFoxProjectile();

        shared::types::Vector2i &getDirection();
        shared::types::Vector2i &getPosition();
        shared::types::Vector2i &getStartingPosition();
        const ProjectileType &getType() const;
        void moveProjectile();
        unsigned int getProjectileTravelDistance();

    private:
        shared::types::Vector2u _getOriginFromDirection();

        ProjectileType _type;
        shared::types::Vector2i _direction;
        shared::types::Vector2i _position;
        shared::types::Vector2i _startingPosition;
        components::TextureProps _textureProps;
};

static components::TextureProps SolarFoxEnemyProjectileTextureProps = {
    .sources = {
        .ascii = "assets/solarfox/projectile.txt",
        .bin = "assets/games/solarfox/projectiles/player_beam_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};

static components::TextureProps SolarFoxPlayerProjectileTextureProps = {
    .sources = {
        .ascii = "assets/solarfox/projectile.txt",
        .bin = "assets/games/solarfox/projectiles/player_beam_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};
