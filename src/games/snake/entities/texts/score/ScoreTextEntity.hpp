/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreTextEntity
*/

#pragma once

#include "components/ScoreTextDisplayable.hpp"
#include "games/IEntity.hpp"

class ScoreTextEntity : public shared::games::entity::IEntity {
    public:
        ScoreTextEntity();
        ~ScoreTextEntity();

        const shared::games::components::ComponentsMap
            &getComponents(void) const noexcept override;

    private:
        shared::games::components::ComponentsMap _components;
};