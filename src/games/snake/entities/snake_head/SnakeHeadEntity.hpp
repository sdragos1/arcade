/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AEntity
*/

#pragma once


#include "components/SnakeHeadCollidable.hpp"
#include "components/SnakeHeadDisplayable.hpp"
#include "components/SnakeHeadKeyboard.hpp"
#include "games/IEntity.hpp"

using namespace shared::games;

class AEntity : public entity::IEntity {
    public:
        AEntity();
        ~AEntity();
        /**
         * @brief Construct a new Snake Head Entity object
         */
        SnakeHeadEntity();

        /**
         * @brief Destroy a new Snake Head Entity object
         */
        ~SnakeHeadEntity();

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const components::ComponentsMap &getComponents(void) const noexcept override;
    protected:

    private:

class SnakeHeadEntity : public entity::IEntity {
    public:
        SnakeHeadEntity();
        ~SnakeHeadEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
};