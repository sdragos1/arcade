/*
** EPITECH PROJECT, 2024
** NcursesSound
** File description:
** Arcade
*/

#include "NcursesSound.hpp"

NcursesSound::NcursesSound(const std::string &path)
{
}

NcursesSound::~NcursesSound()
{
}

void NcursesSound::setState(shared::graphics::ISound::SoundState state)
{
}

shared::graphics::ISound::SoundState NcursesSound::getState() const
{
    return shared::graphics::ISound::SoundState::STOP;
}

void NcursesSound::setVolume(shared::graphics::ISound::SoundVolume volume)
{
}

shared::graphics::ISound::SoundVolume NcursesSound::getVolume() const
{
    return 0;
}

void NcursesSound::setLoopState(bool loop)
{
}

bool NcursesSound::getLoopState(void) const
{
    return false;
}

