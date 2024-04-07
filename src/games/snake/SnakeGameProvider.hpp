/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGameProvider
*/

#ifndef SRC_GAMES_SNAKE_SNAKEGAMEPROVIDER_HPP_
#define SRC_GAMES_SNAKE_SNAKEGAMEPROVIDER_HPP_

#include "games/IGameProvider.hpp"
#include "types/Libraries.hpp"
#include "game/SnakeGame.hpp"

class SnakeGameProvider : public shared::games::IGameProvider {
    public:
        SnakeGameProvider();
        ~SnakeGameProvider();

        const shared::games::GameManifest &getManifest() const noexcept override;
        std::shared_ptr<shared::games::IGame> createInstance() override;
};

#endif  // SRC_GAMES_SNAKE_SNAKEGAMEPROVIDER_HPP_
