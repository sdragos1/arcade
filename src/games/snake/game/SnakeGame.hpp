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

using namespace shared::games;

class SnakeGame : public IGame {
    public:
        SnakeGame();
        ~SnakeGame();

        void compute(DeltaTime dt) override;
        const GameManifest &getManifest(void) const noexcept override;
        const Vector2u getSize(void) const noexcept override;
        const entity::EntitiesMap &getEntities(void) const override;
        std::shared_ptr<entity::IEntity> getEntityById(const UUId &id) const override;

    private:
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
