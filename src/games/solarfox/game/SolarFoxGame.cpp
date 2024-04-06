/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxGame
*/

#include "SolarFoxGame.hpp"

const unsigned int playerSpeed = 40;
const unsigned int playerShootSpeed = 300;
const unsigned int projectileSpeed = 20;
const unsigned int projectileShootSpeed = 500;
const unsigned int enemySpeed = 30;
const unsigned int enemyShootStageSpeed = 420;

SolarFoxGame::SolarFoxGame()
    : _entities() ,
    _player(nullptr),
    _enemies(),
    _projectiles(),
    _powerups(),
    _score(nullptr),
    _playerMoveTime(std::chrono::milliseconds(0)),
    _playerShootTime(std::chrono::milliseconds(0)),
    _projectileMoveTime(std::chrono::milliseconds(0)),
    _playerProjectileShootTime(std::chrono::milliseconds(0)),
    _enemyMoveTime(std::chrono::milliseconds(0))
{
    _score = std::make_shared<SolarFoxScore>();
    _gameInit();
}

void SolarFoxGame::_initPowerups()
{
    for (int i = 0; i < 5; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> disX(WALKABLE_AREA_BEGIN_X, WALKABLE_AREA_END_X);
        std::uniform_int_distribution<int> disY(WALKABLE_AREA_BEGIN_Y, WALKABLE_AREA_END_Y);
        int powerupX = disX(gen);
        int powerupY = disY(gen);

        std::shared_ptr<SolarFoxPowerup> powerup = std::make_shared<SolarFoxPowerup>(
            shared::types::Vector2f(powerupX, powerupY));
        _entities.push_back(powerup);
        _powerups.push_back(powerup);
    }
}

void SolarFoxGame::_initEnemies()
{
    _addEnemy({0, 0}, {1, 1}, {1, 0}, {-1, 0});
    _addEnemy({static_cast<float>(solarFoxGameSize.x - 1),
        static_cast<float>(solarFoxGameSize.y - 1)}, {1, 1}, {3, 0}, {1, 0});
    _addEnemy({static_cast<float>(solarFoxGameSize.x - 1), 0}, {1, 1}, {0, 0},
        {0, 1});
    _addEnemy({0, static_cast<float>(solarFoxGameSize.y - 1)}, {1, 1}, {2, 0},
        {0, -1});
}

void SolarFoxGame::_initPlayer()
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
    _updateTimes(dt);
    _computePowerups();
    _computePlayer();
    _computeEnemies();
    _computerProjectiles();
}

void SolarFoxGame::_updateTimes(DeltaTime dt)
{
    _playerMoveTime -= dt;
    _projectileMoveTime -= dt;
    _playerProjectileShootTime -= dt;
    _enemyMoveTime -= dt;
    _enemyShootStageTime -= dt;
    _playerShootTime -= dt;
}

void SolarFoxGame::_computePlayer()
{
    if (_playerMoveTime >= std::chrono::milliseconds(playerSpeed)) {
        _forwardPlayer();
        _playerMoveTime = std::chrono::milliseconds(0);
    }
    if (_playerShootTime >= std::chrono::milliseconds(playerShootSpeed) &&
        _player->isShooting() == true) {
        _playerShoot();
        _playerShootTime = std::chrono::milliseconds(0);
    }
}

void SolarFoxGame::_computeEnemies()
{
    if (_enemyMoveTime >= std::chrono::milliseconds(enemySpeed)) {
        _moveEnemies();
        _enemyMoveTime = std::chrono::milliseconds(0);
    }
    if (_enemyShootStageTime >= std::chrono::milliseconds(enemyShootStageSpeed)) {
        _handleEnemyShoot();
        _enemyShootStageTime = std::chrono::milliseconds(0);
    }
}

void SolarFoxGame::_computePowerups()
{
    for (int i = 0; i < _powerups.size(); i++) {
        for (auto &component : _powerups[i]->getComponents()) {
            if (component->getType() == components::COLLIDABLE) {
                auto collidable = std::dynamic_pointer_cast<SolarFoxPowerupCollidable>(component);
                if (collidable->isDestroyed() == true) {
                    _entities.erase(std::remove(_entities.begin(), _entities.end(),
                        _powerups[i]), _entities.end());
                    _powerups.erase(_powerups.begin() + i);
                    _score->increaseScore(100);
                }
            }
        }
    }
    if (_powerups.size() == 0) {
        _gameRestart();
    }
}

void SolarFoxGame::_computerProjectiles()
{
    for (int i = 0; i < _projectiles.size(); i++) {
        if (_projectiles[i]->isDestroyed()) {
            _removeProjectile(_projectiles[i]);
        }
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
    float moveSpeed = 0.2;

    if (keyboard->isBoost())
        moveSpeed = 0.3;
    switch (lastDirection)
    {
        case components::IKeyboardComponent::ArrowCode::UP:
            if (pos.y > WALKABLE_AREA_BEGIN_Y) {
                displayable->getPosition().y -= moveSpeed;
            }
            break;
        case components::IKeyboardComponent::ArrowCode::DOWN:
            if (pos.y < WALKABLE_AREA_END_Y) {
                displayable->getPosition().y += moveSpeed;
            }
            break;
        case components::IKeyboardComponent::ArrowCode::LEFT:
            if (pos.x > WALKABLE_AREA_BEGIN_X) {
                displayable->getPosition().x -= moveSpeed;
            }
            break;
        case components::IKeyboardComponent::ArrowCode::RIGHT:
            if (pos.x < WALKABLE_AREA_END_X) {
                displayable->getPosition().x += moveSpeed;
            }
            break;
    }
}

void SolarFoxGame::_forwardProjectiles()
{
    unsigned int travelDistance = 0;
    ProjectileType projectileType;

    for (int i = 0; i < _projectiles.size(); i++) {
        auto projectile = _projectiles[i];
        travelDistance = projectile->getProjectileTravelDistance();
        projectileType = projectile->getType();
        if (projectileType == PLAYER) {
            if (travelDistance >= 3) {
                _removeProjectile(projectile);
                continue;
            }
        }
        if (projectileType == ENEMY) {
            if (travelDistance >= 15) {
                _removeProjectile(projectile);
                continue;
            }
        }
        projectile->moveProjectile();
    }
}

void SolarFoxGame::addProjectile(ProjectileType type,
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
    addProjectile(PLAYER, position, direction);
}

void SolarFoxGame::_enemyShoot(int i)
{
    std::shared_ptr<TextureComponent> displayable = nullptr;

    for (auto &component : _enemies[i]->getComponents()) {
        if (component->getType() == components::TEXTURE) {
            displayable = std::dynamic_pointer_cast<TextureComponent>(component);
        }
    }
    if (displayable == nullptr)
        return;
    shared::types::Vector2f position = displayable->getPosition();
    shared::types::Vector2f direction = {0, 0};
    if (position.x == 0) {
        direction.x = 1;
    }
    if (position.x == solarFoxGameSize.x - 1) {
        direction.x = -1;
    }
    if (position.y == 0) {
        direction.y = 1;
    }
    if (position.y == solarFoxGameSize.y - 1) {
        direction.y = -1;
    }
    addProjectile(ENEMY, position, direction);
}

void SolarFoxGame::_addEnemy(shared::types::Vector2f position, shared::types::Vector2u size,
    shared::types::Vector2u origin, shared::types::Vector2i direction)
{
    std::shared_ptr<SolarFoxEnemy> enemy = std::make_shared<SolarFoxEnemy>(
        position, size, origin, direction);

    _enemies.push_back(enemy);
    _entities.push_back(enemy);
}

void SolarFoxGame::_moveEnemies()
{
    for (int i = 0; i < _enemies.size(); i++) {
        auto enemy = _enemies[i];
        std::shared_ptr<TextureComponent> displayable = nullptr;

        for (auto &component : enemy->getComponents()) {
            if (component->getType() == components::TEXTURE) {
                displayable = std::dynamic_pointer_cast<TextureComponent>(component);
            }
        }
        if (displayable == nullptr)
            continue;
        auto pos = displayable->getPosition();
        const int maxX = solarFoxGameSize.x - 1;
        const int maxY = solarFoxGameSize.y - 1;
        if (pos.x == 0 && pos.y == 0) {
            enemy->inverseDirection();
        }
        if (pos.x == maxX && pos.y == 0) {
            enemy->inverseDirection();
        }
        if (pos.x == maxX && pos.y == maxY) {
            enemy->inverseDirection();
        }
        if (pos.x == 0 && pos.y == maxY) {
            enemy->inverseDirection();
        }
        enemy->move();
    }
}

void SolarFoxGame::_handleEnemyShoot()
{
    for (int i = 0; i < _enemies.size(); i++) {
        if (_enemies[i]->isReadyToShoot()) {
            _enemyShoot(i);
        }
        _enemies[i]->incrementShootingStage();
    }
}

void SolarFoxGame::_gameRestart()
{
    _entities.clear();
    _player = nullptr;
    _enemies.clear();
    _projectiles.clear();
    _powerups.clear();
    _playerMoveTime = std::chrono::milliseconds(0);
    _projectileMoveTime = std::chrono::milliseconds(0);
    _playerProjectileShootTime = std::chrono::milliseconds(0);
    _enemyMoveTime = std::chrono::milliseconds(0);
    _gameInit();
}

void SolarFoxGame::_gameInit()
{
    _entities.push_back(_score);
    _initPowerups();
    _initEnemies();
    _initPlayer();
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
