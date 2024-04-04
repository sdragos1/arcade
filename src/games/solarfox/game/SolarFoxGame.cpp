/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#include "SolarFoxGame.hpp"

const unsigned int playerSpeed = 40;
const unsigned int projectileSpeed = 20;
const unsigned int projectileShootSpeed = 500;

SolarFoxGame::SolarFoxGame()
    : _entities() ,
    _player(nullptr),
    _enemies(),
    _projectiles(),
    _playerMoveTime(std::chrono::milliseconds(0)),
    _projectileMoveTime(std::chrono::milliseconds(0)),
    _playerProjectileShootTime(std::chrono::milliseconds(0))
{
    std::shared_ptr<entity::IEntity> player = std::make_shared<SolarFoxPlayer>();

    _addEnemy({0, 0}, {1, 1}, {0, 0});
    _addEnemy({static_cast<float>(solarFoxGameSize.x - 1),
        static_cast<float>(solarFoxGameSize.y - 1)}, {1, 1}, {0, 0});
    _addEnemy({static_cast<float>(solarFoxGameSize.x - 1), 0}, {1, 1}, {0, 0});
    _addEnemy({0, static_cast<float>(solarFoxGameSize.y - 1)}, {1, 1}, {0, 0});
    _player = std::dynamic_pointer_cast<SolarFoxPlayer>(player);
    _entities.push_back(player);
    _playerShoot();
}

SolarFoxGame::~SolarFoxGame()
{
}

void SolarFoxGame::compute(DeltaTime dt)
{
    _playerMoveTime -= dt;
    _projectileMoveTime -= dt;
    _playerProjectileShootTime -= dt;

    if (_playerMoveTime >= std::chrono::milliseconds(playerSpeed)) {
        _forwardPlayer();
        _playerMoveTime = std::chrono::milliseconds(0);
    }
    if (_projectileMoveTime >= std::chrono::milliseconds(projectileSpeed)) {
        _forwardProjectiles();
        _projectileMoveTime = std::chrono::milliseconds(0);
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
    auto pos = displayable->getPosition();

    switch (lastDirection)
    {
        case components::IKeyboardComponent::ArrowCode::UP:
            if (pos.y > 2) {
                displayable->getPosition().y -= 0.2;
            }
            break;
        case components::IKeyboardComponent::ArrowCode::DOWN:
            if (pos.y < solarFoxGameSize.y - 3) {
                displayable->getPosition().y += 0.2;
            }
            break;
        case components::IKeyboardComponent::ArrowCode::LEFT:
            if (pos.x > 2) {
                displayable->getPosition().x -= 0.2;
            }
            break;
        case components::IKeyboardComponent::ArrowCode::RIGHT:
            if (pos.x < solarFoxGameSize.x - 3) {
                displayable->getPosition().x += 0.2;
            }
            break;
    }
}

void SolarFoxGame::_forwardProjectiles()
{
    for (int i = 0; i < _projectiles.size(); i++) {
        auto projectile = _projectiles[i];

        if (projectile->getProjectileTravelDistance() > 3) {
            _removeProjectile(projectile);
            _playerShoot();
            continue;
        }
        projectile->moveProjectile();
    }
}

void SolarFoxGame::addProjectile(SolarFoxProjectile::ProjectileType type,
    shared::types::Vector2f position,
    shared::types::Vector2f direction)
{
    std::shared_ptr<SolarFoxProjectile> projectile = std::make_shared<SolarFoxProjectile>(
        type,
        position,
        direction);

    _projectiles.push_back(projectile);
    _entities.push_back(projectile);
}

void SolarFoxGame::_removeProjectile(std::shared_ptr<SolarFoxProjectile> projectile)
{
    _projectiles.erase(std::remove(_projectiles.begin(), _projectiles.end(),
        projectile), _projectiles.end());
    _entities.erase(std::remove(_entities.begin(), _entities.end(), projectile), _entities.end());
}

void SolarFoxGame::_playerShoot()
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
    shared::types::Vector2f position = displayable->getPosition();
    shared::types::Vector2f direction = {0, 0};

    switch (lastDirection)
    {
        case components::IKeyboardComponent::ArrowCode::UP:
            direction.y = -1;
            break;
        case components::IKeyboardComponent::ArrowCode::DOWN:
            direction.y = 1;
            break;
        case components::IKeyboardComponent::ArrowCode::LEFT:
            direction.x = -1;
            break;
        case components::IKeyboardComponent::ArrowCode::RIGHT:
            direction.x = 1;
            break;
    }
    addProjectile(SolarFoxProjectile::PLAYER, position, direction);
}

void SolarFoxGame::_addEnemy(shared::types::Vector2f position, shared::types::Vector2u size,
    shared::types::Vector2u origin)
{
    std::shared_ptr<SolarFoxEnemy> enemy = std::make_shared<SolarFoxEnemy>(
        position, size, origin);

    _enemies.push_back(enemy);
    _entities.push_back(enemy);
}

const GameManifest &SolarFoxGame::getManifest(void) const noexcept
{
    return solarFoxManifest;
}

const Vector2u SolarFoxGame::getSize(void) const noexcept
{
    return solarFoxGameSize;
}

const entity::EntitiesMap &SolarFoxGame::getEntities(void) const
{
    return _entities;
}

const unsigned int SolarFoxGame::getFps() const noexcept
{
    return 60;
}

const int SolarFoxGame::getScore() const noexcept
{
    return 0;
}
