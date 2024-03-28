/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreEntity
*/

#include "ScoreEntity.hpp"

ScoreEntity::ScoreEntity()
    : _components()
{
    std::shared_ptr<ScoreText> scoreText = std::make_shared<ScoreText>("Score: 0", *this);
    _components.push_back(scoreText);
}

ScoreEntity::~ScoreEntity()
{
}

const shared::games::components::ComponentsMap &ScoreEntity::getComponents(void) const noexcept
{
    return _components;
}
