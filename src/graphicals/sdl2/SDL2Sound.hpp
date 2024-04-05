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
        /**
         * @brief Construct a new SDL2Sound object
         * @param path
         */
        explicit SDL2Sound(const std::string &path);

        /**
         * @brief Destroy the SDL2Sound object
         */
        ~SDL2Sound();

        /**
         * @brief Set the sound state
         * @param state
         */
        void setState(shared::graphics::ISound::SoundState) override;

        /**
         * @brief Get the sound state
         * @return shared::graphics::ISound::SoundState
         */
        shared::graphics::ISound::SoundState getState() const override;

        /**
         * @brief Set the volume of the sound
         * @param volume
         */
        void setVolume(shared::graphics::ISound::SoundVolume volume) override;

        /**
         * @brief Get the volume of the sound
         * @return shared::graphics::ISound::SoundVolume
         */
        shared::graphics::ISound::SoundVolume getVolume() const override;

        /**
         * @brief Set the sound to loop or not
         * @param loop
         */
        void setLoopState(bool loop) override;

        /**
         * @brief Get the loop state
         * @return bool
         */
        bool getLoopState(void) const override;

    private:
        bool                                 _loop;
        Mix_Music                           *_sound;
        shared::graphics::ISound::SoundState _state;
};

