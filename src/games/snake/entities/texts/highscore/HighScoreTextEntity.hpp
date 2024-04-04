/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** HighScoreTextEntity
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "components/HighScoreTextDisplayable.hpp"
#include "games/IEntity.hpp"

class HighScoreTextEntity : public shared::games::entity::IEntity {
    public:

        /**
         * @brief Construct a new Score Text Entity object
         * @param playerScoresList
         */
        HighScoreTextEntity();

        /**
         * @brief Destroy a new Score Text Entity object
         */
        ~HighScoreTextEntity();

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const shared::games::components::ComponentsMap
            &getComponents(void) const noexcept override;

        std::shared_ptr<HighScoreTextDisplayable> getHighScores(void) const noexcept;

    private:
        shared::games::components::ComponentsMap _components;
};