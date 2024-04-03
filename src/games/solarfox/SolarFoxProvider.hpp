/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProvider
*/

#pragma once

#include "types/Libraries.hpp"
#include "games/IGameProvider.hpp"
#include "game/SolarFoxGame.hpp"

class SolarFoxProvider : public IGameProvider {
    public:
        SolarFoxProvider();
        ~SolarFoxProvider();

        const GameManifest &getManifest() const noexcept override;
        std::shared_ptr<IGame> createInstance(void) override;
};
