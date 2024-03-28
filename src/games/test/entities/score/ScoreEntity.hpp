/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreEntity
*/

#pragma once

#include "components/ScoreText.hpp"
#include "games/IEntity.hpp"

class ScoreEntity : public shared::games::entity::IEntity {
    public:
        ScoreEntity();
        ~ScoreEntity();

        const shared::games::components::ComponentsMap
            &getComponents(void) const noexcept override;

    private:
        shared::games::components::ComponentsMap _components;
};
