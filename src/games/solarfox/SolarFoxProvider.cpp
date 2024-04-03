/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProvider
*/

#include "SolarFoxProvider.hpp"

SolarFoxProvider::SolarFoxProvider()
{
}

SolarFoxProvider::~SolarFoxProvider()
{
}

const GameManifest &SolarFoxProvider::getManifest() const noexcept
{
    return solarFoxManifest;
}

std::shared_ptr<IGame> SolarFoxProvider::createInstance(void)
{
    return std::make_shared<SolarFoxGame>();
}

extern "C" shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
{
    return shared::types::LibraryType::GAME;
}

extern "C" shared::games::IGameProvider *SHARED_GAME_PROVIDER_GETTER_NAME(void)
{
    return new SolarFoxProvider();
}
