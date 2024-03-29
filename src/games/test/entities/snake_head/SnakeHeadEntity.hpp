/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadEntity
*/

#pragma once

#include "components/SnakeHeadDisplayable.hpp"
#include "components/SnakeHeadKeyboard.hpp"
#include "games/IEntity.hpp"

using namespace shared::games;

class SnakeHeadEntity : public entity::IEntity {
    public:
        SnakeHeadEntity();
        ~SnakeHeadEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;
    private:
        components::ComponentsMap _components;
};