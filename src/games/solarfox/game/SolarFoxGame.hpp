/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#pragma once

#include "../entities/player/SolarFoxPlayer.hpp"
#include "games/IGame.hpp"

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

    private:
        entity::EntitiesMap _entities;
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
