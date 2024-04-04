/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#include "SolarFoxGame.hpp"

const unsigned int playerSpeed = 200;

SolarFoxGame::SolarFoxGame()
    : _entities()
{
    std::shared_ptr<entity::IEntity> player = std::make_shared<SolarFoxPlayer>();

    _player = std::dynamic_pointer_cast<SolarFoxPlayer>(player);
    _entities.push_back(player);
}

SolarFoxGame::~SolarFoxGame()
{
}

void SolarFoxGame::compute(DeltaTime dt)
{
    _playerMoveTime -= dt;

    if (_playerMoveTime >= std::chrono::milliseconds(playerSpeed)) {
        _forwardPlayer();
        _playerMoveTime = std::chrono::milliseconds(0);
    }
}

void SolarFoxGame::_forwardPlayer()
{
    std::shared_ptr<TextureComponent> displayable = nullptr;
    std::shared_ptr<SolarFoxPlayerKeyboard> keyboard = nullptr;

    for (auto &component : _player->getComponents()) {
        if (component->getType() == components::TEXTURE) {
            displayable = std::dynamic_pointer_cast<TextureComponent>(component);
        }
        if (component->getType() == components::KEYBOARD) {
            keyboard = std::dynamic_pointer_cast<SolarFoxPlayerKeyboard>(component);
        }
    }
    if (displayable == nullptr)
        return;
    auto lastDirection = keyboard->getLastDirection();
    switch (lastDirection)
    {
        case components::IKeyboardComponent::ArrowCode::UP:
            displayable->getPosition().y -= 1;
            break;
        case components::IKeyboardComponent::ArrowCode::DOWN:
            displayable->getPosition().y += 1;
            break;
        case components::IKeyboardComponent::ArrowCode::LEFT:
            displayable->getPosition().x -= 1;
            break;
        case components::IKeyboardComponent::ArrowCode::RIGHT:
            displayable->getPosition().x += 1;
            break;
    }
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
