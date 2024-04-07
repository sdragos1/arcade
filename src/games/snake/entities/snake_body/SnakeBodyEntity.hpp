/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyEntity
*/

#pragma once

#include "components/SnakeBodyDisplayable.hpp"
#include "components/SnakeBodyCollidable.hpp"
#include "games/IEntity.hpp"

using namespace shared::games;

class SnakeBodyEntity : public entity::IEntity {
    public:
        /**
         * @brief Construct a new Snake Body Entity object
         * @param position
         */
        SnakeBodyEntity(Vector2f position, unsigned int id);

        /**
         * @brief Destroy a new Snake Body Entity object
         */
        ~SnakeBodyEntity();

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        components::ComponentsMap _components;
        unsigned int _id;
};
