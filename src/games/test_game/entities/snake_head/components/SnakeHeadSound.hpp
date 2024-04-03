/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadSound
*/

#pragma once

#include "abstracts/sound/ASoundComponent.hpp"

using namespace shared::games;

class SnakeHeadSound : public ASoundComponent {
    public:
        explicit SnakeHeadSound(const entity::IEntity &_entity, const std::string &path);
        ~SnakeHeadSound();

        void onStateChange(std::shared_ptr<IGame> ctx, components::SoundState state) override;
};
