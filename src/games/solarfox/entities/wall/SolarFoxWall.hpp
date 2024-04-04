/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** InvisibleWall
*/

#pragma once

#include "components/SolarFoxWallCollidable.hpp"
#include "abstracts/entity/AEntity.hpp"
#include "types/Vector.hpp"
#include "../../CollisionLayers.hpp"

class SolarFoxWall : public AEntity {
    public:
        SolarFoxWall(shared::types::Vector2i position, shared::types::Vector2u size,
            std::vector<solarfox::CollisionLayer> collisionLayers);
        ~SolarFoxWall();

        std::vector<solarfox::CollisionLayer> getCollisionLayers() const;

    private:
        std::vector<solarfox::CollisionLayer> _collisionLayers;
};
