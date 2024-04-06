/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ASoundComponent
*/

#pragma once

#include "games/components/ISoundComponent.hpp"

using namespace shared::games;

class ASoundComponent : public components::ISoundComponent {
    public:
        ASoundComponent(const entity::IEntity &_entity, const std::string &path);
        ~ASoundComponent();

        const std::string &getPath(void) const noexcept override;
        components::SoundState &getState(void) noexcept override;
        components::SoundVolume &getVolume(void) noexcept override;
        bool &getLoop(void) noexcept override;
        const components::ComponentType getType(void) const noexcept override;
        const entity::IEntity &getEntity(void) noexcept override;

    protected:
        std::string _path;
        components::SoundState _state;
        components::SoundVolume _volume;
        bool _loop;
        const entity::IEntity &_entity;
};
