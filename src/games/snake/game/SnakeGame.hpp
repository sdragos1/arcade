/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGame
*/

#ifndef SNAKEGAME_HPP_
#define SNAKEGAME_HPP_

#include <iostream>
#include <list>
#include "games/IGame.hpp"
#include "../entities/snake_head/SnakeHeadEntity.hpp"
#include "../entities/snake_body/SnakeBodyEntity.hpp"
#include "../entities/snake_tail/SnakeTailEntity.hpp"
#include "../entities/apple/AppleEntity.hpp"
#include "../entities/texts/score/ScoreTextEntity.hpp"

using namespace shared::games;

class SnakeGame : public IGame {
    public:
        SnakeGame();
        ~SnakeGame();

        void compute(DeltaTime dt) override;
        const GameManifest &getManifest() const noexcept override;
        const Vector2u getSize(void) const noexcept override;
        const entity::EntitiesMap &getEntities(void) const override;
        const unsigned int getFps(void) const noexcept override;

        void moveSnake(int x, int y);

    protected:
    private:
        std::list<std::shared_ptr<entity::IEntity>> _snakeEntities;
        entity::EntitiesMap _entities;
};

static GameManifest snakeGameManifest = {
    "Snake",
    "Snake game for Epitech's arcade project",
    "1.0",
    {
        {
            "BxpitsteM",
            "",
            "github"
        }
    }
};

#endif /* !SNAKEGAME_HPP_ */
