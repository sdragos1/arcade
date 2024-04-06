/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxEnemy
*/

#pragma once

#include "abstracts/components/TextureComponent.hpp"
#include "abstracts/entity/AEntity.hpp"

class SolarFoxEnemy : public AEntity {
    public:
        SolarFoxEnemy(shared::types::Vector2f position, shared::types::Vector2u size,
            shared::types::Vector2u origin, shared::types::Vector2i direction);
        ~SolarFoxEnemy();

        void inverseDirection();
        shared::types::Vector2i getDirection() const;
        void move();
        void incrementShootingStage();
        bool isReadyToShoot();

    private:
        shared::types::Vector2i _direction;
        components::TextureProps _textureProps;
        std::size_t _shootingStage;
        std::shared_ptr<TextureComponent> _texture;
};

static components::TextureProps SolarEnemyTextureProps = {
    .sources = {
        .ascii = "assets/games/solarfox/enemies/bonbon_sheet.ascii",
        .bin = "assets/games/solarfox/enemies/bonbon_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};

