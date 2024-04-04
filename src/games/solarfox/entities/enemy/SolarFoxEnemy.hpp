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
        SolarFoxEnemy(shared::types::Vector2i position, shared::types::Vector2u size,
            shared::types::Vector2u origin);
        ~SolarFoxEnemy();
};

static components::TextureProps SolarEnemyTextureProps = {
    .sources = {
        .ascii = "assets/solarfox/player.txt",
        .bin = "assets/games/solarfox/enemies/bonbon_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};

