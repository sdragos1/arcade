/*
** EPITECH PROJECT, 2024
** SDL2Sound
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include "../../../common/graphics/ISound.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class NcursesSound : public shared::graphics::ISound
{
    public:
        explicit NcursesSound(const std::string &path);

        ~NcursesSound();

        void setState(shared::graphics::ISound::SoundState) override;
        shared::graphics::ISound::SoundState getState() const override;
        void setVolume(shared::graphics::ISound::SoundVolume volume) override;
        shared::graphics::ISound::SoundVolume getVolume() const override;
        void setLoopState(bool loop) override;
        bool getLoopState(void) const override;
};

