/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#include "SolarFoxGame.hpp"

const unsigned int playerSpeed = 200;
const unsigned int projectileSpeed = 50;
const unsigned int projectileShootSpeed = 500;

SolarFoxGame::SolarFoxGame()
    : _entities() ,
    _player(nullptr),
    _projectiles(),
    _playerMoveTime(std::chrono::milliseconds(0)),
    _projectileMoveTime(std::chrono::milliseconds(0)),
    _playerProjectileShootTime(std::chrono::milliseconds(0))
{
    std::shared_ptr<entity::IEntity> player = std::make_shared<SolarFoxPlayer>();

    _player = std::dynamic_pointer_cast<SolarFoxPlayer>(player);
    _entities.push_back(player);
    _playerShoot();
    _addWall({2, 2}, {solarFoxGameSize.x - 4, 1}, {solarfox::CollisionLayer::CENTER_WALL});
    _addWall({2, solarFoxGameSize.y - 3}, {solarFoxGameSize.x - 4, 1},
        {solarfox::CollisionLayer::CENTER_WALL});
    _addWall({2, 2}, {1, solarFoxGameSize.y - 4}, {solarfox::CollisionLayer::CENTER_WALL});
    _addWall({solarFoxGameSize.x - 3, 2}, {1, solarFoxGameSize.y - 4},
        {solarfox::CollisionLayer::CENTER_WALL});
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
    shared::types::Vector2i position,
    shared::types::Vector2i direction)
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
    shared::types::Vector2i position = displayable->getPosition();
    shared::types::Vector2i direction = {0, 0};

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

void SolarFoxGame::_addWall(shared::types::Vector2i position, shared::types::Vector2u size,
    std::vector<solarfox::CollisionLayer> collisionLayers)
{
    std::shared_ptr<SolarFoxWall> wall = std::make_shared<SolarFoxWall>(position, size, collisionLayers);

    _entities.push_back(wall);
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
