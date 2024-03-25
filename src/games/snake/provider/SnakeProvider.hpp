/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeProvider
*/

#pragma once

#include "games/IGameProvider.hpp"
#include "../game/SnakeGame.hpp"

using namespace shared::games;

class SnakeProvider : public IGameProvider {
    public:
        SnakeProvider();
        ~SnakeProvider();

        const GameManifest &getManifest() const noexcept override;
        std::shared_ptr<IGame> createInstance(void) override;
};
