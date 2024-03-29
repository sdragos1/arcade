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
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "exceptions/SDL2SoundException.hpp"
#include "../../../common/graphics/ISound.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class SDL2Sound : public shared::graphics::ISound
{
    public:
        explicit SDL2Sound(const std::string &path);

        ~SDL2Sound();

        void setState(shared::graphics::ISound::SoundState) override;
        shared::graphics::ISound::SoundState getState() const override;
        void setVolume(shared::graphics::ISound::SoundVolume volume) override;
        shared::graphics::ISound::SoundVolume getVolume() const override;
        void setLoopState(bool loop) override;
        bool getLoopState(void) const override;

    private:
        bool                                 _loop;
        Mix_Music                           *_sound;
        shared::graphics::ISound::SoundState _state;
};

