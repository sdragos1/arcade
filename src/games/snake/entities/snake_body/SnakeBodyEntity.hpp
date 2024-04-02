/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyEntity
*/

#pragma once

#include "components/SnakeBodyDisplayable.hpp"
#include "games/IEntity.hpp"

using namespace shared::games;

class SnakeBodyEntity : public entity::IEntity {
    public:
        SnakeBodyEntity(Vector2i position);
        ~SnakeBodyEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        components::ComponentsMap _components;
};