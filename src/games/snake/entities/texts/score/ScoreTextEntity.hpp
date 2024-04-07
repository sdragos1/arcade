/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreTextEntity
*/

#pragma once

#include "components/ScoreTextDisplayable.hpp"
#include "games/IEntity.hpp"
#include <iostream>

class ScoreTextEntity : public shared::games::entity::IEntity {
    public:
        /**
         * @brief Construct a new Score Text Entity object
         */
        ScoreTextEntity();

        /**
         * @brief Destroy a new Score Text Entity object
         */
        ~ScoreTextEntity();

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const shared::games::components::ComponentsMap
            &getComponents(void) const noexcept override;

        void updateScore(int score) noexcept;

    private:
        shared::games::components::ComponentsMap _components;
};
