/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayer
*/

#pragma once

#include "abstracts/components/TextureComponent.hpp"
#include "abstracts/entity/AEntity.hpp"

class SolarFoxPlayer : public AEntity {
    public:
        SolarFoxPlayer();
        ~SolarFoxPlayer();
};

static components::TextureProps SolarPlayerTextureProps = {
    .sources = {
        .ascii = "assets/solarfox/player.txt",
        .bin = "assets/games/solarfox/player/player_ship.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};
