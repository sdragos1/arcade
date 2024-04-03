/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#include "SolarFoxGame.hpp"

SolarFoxGame::SolarFoxGame()
    : _entities()
{
}

SolarFoxGame::~SolarFoxGame()
{
}

void SolarFoxGame::compute(DeltaTime dt)
{
    (void)dt;
}

const GameManifest &SolarFoxGame::getManifest(void) const noexcept
{
    return solarFoxManifest;
}

const Vector2u SolarFoxGame::getSize(void) const noexcept
{
    return {800, 600};
}

const entity::EntitiesMap &SolarFoxGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SolarFoxGame::getFps() const noexcept
{
    return 60;
}
