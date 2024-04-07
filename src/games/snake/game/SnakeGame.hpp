/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGame
*/

#ifndef SNAKEGAME_HPP_
#define SNAKEGAME_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <memory>
#include "games/IGame.hpp"
#include "../entities/snake_head/SnakeHeadEntity.hpp"
#include "../entities/snake_body/SnakeBodyEntity.hpp"
#include "../entities/snake_tail/SnakeTailEntity.hpp"
#include "../entities/apple/AppleEntity.hpp"
#include "../entities/background/BackgroundEntity.hpp"
#include "../entities/texts/score/ScoreTextEntity.hpp"

using namespace shared::games;

class SnakeGame : public IGame {
    public:
        /**
         * @brief Construct a new Snake Game object
         */
        SnakeGame();

        /**
         * @brief Destroy a new Snake Game object
         */
        ~SnakeGame();

        /**
         * @brief Compute the game based on the DeltaTime dt
         * @param dt
         */
        void compute(DeltaTime dt) override;

        /**
         * @brief Get the game manifest object
         * @return const GameManifest&
         */
        const GameManifest &getManifest() const noexcept override;

        /**
         * @brief Get the Size object
         * @return const Vector2u
         */
        const Vector2u getSize(void) const noexcept override;

        /**
         * @brief Get the Entities object
         * @return const entity::EntitiesMap&
         */
        const entity::EntitiesMap &getEntities(void) const override;

        const int getScore() const noexcept override;

        /**
         * @brief Get the Fps object
         * @return const unsigned int
         */
        const unsigned int getFps(void) const noexcept override;

        /**
         * @brief Move the snake
         */
        void moveSnake();

        /**
         * @brief Update the position of the snake
         */
        void updatePosition();

        /**
         * @brief Check if the head has moved
         * @param it
         * @return bool
         */
        bool hasHeadMoved(auto it);

        /**
         * @brief Update the body positions
         * @param it
         * @return The tail position after the update
         */
        Vector2f updateBodyPositions(auto it);

        /**
         * @brief Update the tail position
         * @param position
         */
        void updateTailPosition(Vector2f);

        /**
         * @brief Check if the snake has gone outside of the map and replace at it at the opposite side
         * @param head
         */
        void checkMapExit(std::shared_ptr<SnakeHeadDisplayable> head);

        /**
         * @brief Increases snake score and length
         */
        void increaseSnakeSize();

        /**
         * @brief Increases the difficulty of the game
         * @param score
         * return _moveSpeed
         */
        int increaseDifficulty(int score);

        /**
         * @brief Search for the direction of the snake
         * @param it
         * @return true
         * @return false
         */
        bool findDirection(auto it);

        /**
         * @brief Update the head position
         * @param it
         * @return Vector2f
         */
        Vector2f updateHeadPosition(auto it);

        /**
         * @brief Update the head collidable position
         * @param it
         * @param pos
         */
        void updateHeadCollidablePosition(auto it, Vector2f pos);

        /**
         * @brief Update the body collidable position
         * @param it
         * @param pos
         */
        void updateBodyCollidablePosition(auto it, Vector2f pos);

        /**
         * @brief Update the tail collidable position
         * @param it
         * @param pos
         */
        void updateTailCollidablePosition(auto it, Vector2f pos);

        /**
         * @brief Update the apple position
         */
        void updateApplePosition();

        /**
         * @brief Check if the player has lost
         * @return true
         * @return false
         */
        bool checkLose();

        /**
         * @brief Init the game
         */
        void gameInit();

    private:
        entity::EntitiesMap _entities;
        SnakeHeadKeyboard::Direction _direction;
        std::list<std::shared_ptr<entity::IEntity>> _snakeEntities;
        DeltaTime _moveCd;
        int _moveSpeed;
        unsigned int _prevScore;
};

/**
 * @brief Definition of the game manifest
 */
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
