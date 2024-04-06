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
#include "components/SolarFoxPlayerCollidable.hpp"

class SolarFoxPlayer : public AEntity {
    public:
        SolarFoxPlayer();
        ~SolarFoxPlayer();

        bool isShooting() const;
        bool isDestroyed() const;
};

static components::TextureProps SolarPlayerTextureProps = {
    .sources = {
        .ascii = "assets/games/solarfox/player/player_ship_sheet.ascii",
        .bin = "assets/games/solarfox/player/player_ship_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};
