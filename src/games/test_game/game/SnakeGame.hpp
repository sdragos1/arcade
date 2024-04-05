/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** Snake
*/

#pragma once

#include <iostream>
#include "games/IGame.hpp"
#include "../entities/snake_head/SnakeHeadEntity.hpp"
#include "../entities/score/ScoreEntity.hpp"

using namespace shared::games;

class SnakeGame : public IGame {
    public:
        SnakeGame();
        ~SnakeGame();

        void compute(DeltaTime dt) override;
        const GameManifest &getManifest(void) const noexcept override;
        const Vector2u getSize(void) const noexcept override;
        const entity::EntitiesMap &getEntities(void) const override;
        const unsigned int getFps() const noexcept override;
        const int getScore() const noexcept override;

    private:
        int _score;
        entity::EntitiesMap _entities;
};

static GameManifest snakeManifest = {
    "Snake",
    "A simple snake game",
    "1.0",
    {
        {
            "Arthur Sonzogni",
            "",
            "github"
        }
    }
};
