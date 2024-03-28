/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailEntity
*/

#pragma once

#include "components/SnakeTailDisplayable.hpp"
#include "components/SnakeTailKeyboard.hpp"
#include "games/IEntity.hpp"

using namespace shared::games;

class SnakeTailEntity : public entity::IEntity {
    public:
        SnakeTailEntity();
        ~SnakeTailEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        components::ComponentsMap _components;
};