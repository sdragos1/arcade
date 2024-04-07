/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailEntity
*/

#pragma once

#include "components/SnakeTailDisplayable.hpp"
#include "components/SnakeTailCollidable.hpp"
#include "games/IEntity.hpp"

using namespace shared::games;

class SnakeTailEntity : public entity::IEntity {
    public:
        /**
         * @brief Construct a new Snake Tail Entity object
         */
        SnakeTailEntity();

        /**
         * @brief Destroy a new Snake Tail Entity object
         */
        ~SnakeTailEntity();

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        components::ComponentsMap _components;
};