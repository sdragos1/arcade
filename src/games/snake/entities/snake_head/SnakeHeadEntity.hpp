/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AEntity
*/

#pragma once

<<<<<<<< HEAD:src/games/abstracts/entity/AEntity.hpp
========
#include "components/SnakeHeadDisplayable.hpp"
#include "components/SnakeHeadKeyboard.hpp"
#include "components/SnakeHeadCollidable.hpp"
>>>>>>>> main:src/games/snake/entities/snake_head/SnakeHeadEntity.hpp
#include "games/IEntity.hpp"

using namespace shared::games;

class AEntity : public entity::IEntity {
    public:
<<<<<<<< HEAD:src/games/abstracts/entity/AEntity.hpp
        AEntity();
        ~AEntity();
========
        /**
         * @brief Construct a new Snake Head Entity object
         */
        SnakeHeadEntity();

        /**
         * @brief Destroy a new Snake Head Entity object
         */
        ~SnakeHeadEntity();
>>>>>>>> main:src/games/snake/entities/snake_head/SnakeHeadEntity.hpp

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const components::ComponentsMap &getComponents(void) const noexcept override;
<<<<<<<< HEAD:src/games/abstracts/entity/AEntity.hpp
    protected:
========

    private:
>>>>>>>> main:src/games/snake/entities/snake_head/SnakeHeadEntity.hpp
        components::ComponentsMap _components;
};