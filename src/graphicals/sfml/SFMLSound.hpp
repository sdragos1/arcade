/*
** EPITECH PROJECT, 2024
** SFMLSound
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "exceptions/SFMLSoundException.hpp"
#include "../../../common/graphics/ISound.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class SFMLSound : public shared::graphics::ISound
{
    public:

        /**
         * @brief Construct a new SFMLSound object
         * @param path
         */
        explicit SFMLSound(const std::string &path);

        /**
         * @brief Destroy the SFMLSound object
         */
        ~SFMLSound();

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
         */
        void setLoopState(bool loop) override;

        /**
         * @brief Get the loop state of the sound
         * @return bool
         */
        bool getLoopState(void) const override;

    private:
        sf::Sound                            _sound;
        sf::SoundBuffer                      _bufferSound;
        shared::graphics::ISound::SoundState _state;
};

