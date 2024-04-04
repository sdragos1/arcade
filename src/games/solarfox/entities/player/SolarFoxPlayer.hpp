/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayer
*/

#pragma once

#include "abstracts/components/TextureComponent.hpp"
#include "abstracts/entity/AEntity.hpp"
#include "components/SolarFoxPlayerKeyboard.hpp"
#include "../../CollisionLayers.hpp"

class SolarFoxPlayer : public AEntity {
    public:
        SolarFoxPlayer();
        ~SolarFoxPlayer();

        std::vector<solarfox::CollisionLayer> getCollisionLayers() const;
};

static std::vector<solarfox::CollisionLayer> SolarPlayerCollisionLayers = {
    solarfox::CollisionLayer::PLAYER,
    solarfox::CollisionLayer::ENEMY,
    solarfox::CollisionLayer::CENTER_WALL,
};

static components::TextureProps SolarPlayerTextureProps = {
    .sources = {
        .ascii = "assets/solarfox/player.txt",
        .bin = "assets/games/solarfox/player/player_ship_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};
