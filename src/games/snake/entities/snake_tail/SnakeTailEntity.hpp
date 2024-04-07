/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailEntity
*/

#pragma once

#include "components/SnakeTailDisplayable.hpp"
<<<<<<< HEAD
#include "components/SnakeTailCollidable.hpp"
=======
#include "components/SnakeTailKeyboard.hpp"
>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)
#include "games/IEntity.hpp"

using namespace shared::games;

class SnakeTailEntity : public entity::IEntity {
    public:
<<<<<<< HEAD
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
=======
        SnakeTailEntity();
        ~SnakeTailEntity();

>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)
        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        components::ComponentsMap _components;
<<<<<<< HEAD
};
=======
};
>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)
