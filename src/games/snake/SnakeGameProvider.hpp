/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeGameProvider
*/

#ifndef SNAKEGAMEPROVIDER_HPP_
#define SNAKEGAMEPROVIDER_HPP_

#include "games/IGameProvider.hpp"
#include "types/Libraries.hpp"
#include "game/SnakeGame.hpp"

using namespace shared::games;

class SnakeGameProvider : public IGameProvider {
    public:
        SnakeGameProvider();
        ~SnakeGameProvider();

        const GameManifest &getManifest() const noexcept override;
        std::shared_ptr<IGame> createInstance() override;
};

#endif /* !SNAKEGAMEPROVIDER_HPP_ */
