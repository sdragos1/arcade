/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AEntity
*/

#pragma once

#include "games/IEntity.hpp"

using namespace shared::games;

class AEntity : public entity::IEntity {
    public:
        AEntity();
        ~AEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;
    protected:
        components::ComponentsMap _components;
};
