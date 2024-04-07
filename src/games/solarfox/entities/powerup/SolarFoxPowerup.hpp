/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPowerup
*/

#pragma once

#include "Powerup.hpp"
#include "components/SolarFoxPowerupCollidable.hpp"
#include "abstracts/components/TextureComponent.hpp"
#include "abstracts/entity/AEntity.hpp"

class SolarFoxPowerup : public AEntity {
    public:
        SolarFoxPowerup(Vector2f pos, PowerupType type);
        ~SolarFoxPowerup();

        PowerupType getPowerupType() const;

    private:
        PowerupType _type;
};

static components::TextureProps SolarFoxPowerupTextureProps = {
    .sources = {
        .ascii = "assets/games/solarfox/powerup/powerup_sheet.ascii",
        .bin = "assets/games/solarfox/powerup/powerup_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {0, 0},
};

static components::TextureProps SolarFoxPowerupBadTextureProps = {
    .sources = {
        .ascii = "assets/games/solarfox/powerup/powerup_sheet.ascii",
        .bin = "assets/games/solarfox/powerup/powerup_sheet.png",
        .binTileSize = {16, 16},
    },
    .origin = {1, 0},
};
