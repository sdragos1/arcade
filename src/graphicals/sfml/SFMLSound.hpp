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
#include "graphics/ISound.hpp"
#include "types/Libraries.hpp"
#include "graphics/IGraphicsProvider.hpp"

class SFMLSound : public shared::graphics::ISound
{
    public:
        explicit SFMLSound(const std::string &path);

        ~SFMLSound();

        void setState(shared::graphics::ISound::SoundState) override;
        shared::graphics::ISound::SoundState getState() const override;
        void setVolume(shared::graphics::ISound::SoundVolume volume) override;
        shared::graphics::ISound::SoundVolume getVolume() const override;
        void setLoopState(bool loop) override;
        bool getLoopState(void) const override;

    private:
        sf::Sound                            _sound;
        shared::graphics::ISound::SoundState _state;
};

