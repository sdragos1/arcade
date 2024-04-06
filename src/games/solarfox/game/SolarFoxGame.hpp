/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#pragma once

#include <iostream>
#include <random>
#include <algorithm>
#include "../entities/projectile/SolarFoxProjectile.hpp"
#include "../entities/player/SolarFoxPlayer.hpp"
#include "../entities/enemy/SolarFoxEnemy.hpp"
#include "../entities/powerup/SolarFoxPowerup.hpp"
#include "games/IGame.hpp"


static Vector2u solarFoxGameSize = {20, 15};

#define WALKABLE_AREA_BEGIN_X 2
#define WALKABLE_AREA_BEGIN_Y 2
#define WALKABLE_AREA_END_X solarFoxGameSize.x - 3
#define WALKABLE_AREA_END_Y solarFoxGameSize.y - 3

using namespace shared::games;

class SolarFoxGame : public IGame {
    public:
        SolarFoxGame();
        ~SolarFoxGame();

        void compute(DeltaTime dt) override;
        const GameManifest &getManifest(void) const noexcept override;
        const Vector2u getSize(void) const noexcept override;
        const entity::EntitiesMap &getEntities(void) const override;
        const unsigned int getFps() const noexcept override;
        const int getScore() const noexcept;

        void addProjectile(SolarFoxProjectile::ProjectileType type,
            shared::types::Vector2f position,
            shared::types::Vector2f direction);

    private:
        void _initPowerups();
        void _initEnemies();
        void _initPlayer();

        void _updateTimes(DeltaTime dt);
        void _computeEnemies();
        void _computePlayer();

        void _addEnemy(shared::types::Vector2f position, shared::types::Vector2u size,
            shared::types::Vector2u origin, shared::types::Vector2i direction);
        void _forwardPlayer();
        void _forwardProjectiles();
        void _moveEnemies();
        void _playerShoot();
        void _removeProjectile(std::shared_ptr<SolarFoxProjectile> projectile);
        void _enemyShoot(int i);
        void _handleEnemyShoot();

        entity::EntitiesMap _entities;
        std::shared_ptr<SolarFoxPlayer> _player;
        std::vector<std::shared_ptr<SolarFoxEnemy>> _enemies;
        std::vector<std::shared_ptr<SolarFoxProjectile>> _projectiles;
        DeltaTime _playerMoveTime;
        DeltaTime _playerProjectileShootTime;
        DeltaTime _projectileMoveTime;
        DeltaTime _enemyMoveTime;
        DeltaTime _enemyShootStageTime;
};

static GameManifest solarFoxManifest = {
    "SolarFox",
    "SolarFox recreation",
    "1.0",
    {
        {
            "Suceveanu Dragos",
            "dragossuceveanu@epitech.eu",
            "https://github.com/sdragos1"
        }
    }
};

