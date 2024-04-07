/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreTextEntity
*/

#include "ScoreTextEntity.hpp"

ScoreTextEntity::ScoreTextEntity()
    : _components()
{
    std::shared_ptr<ScoreTextDisplayable> scoreText =
        std::make_shared<ScoreTextDisplayable>("Score: 0", *this);
    _components.push_back(scoreText);
}

ScoreTextEntity::~ScoreTextEntity()
{
}

void ScoreTextEntity::updateScore(int score) noexcept
{
    for (auto &component : _components) {
        if (component->getType() == shared::games::components::ComponentType::TEXT) {
            auto scoreText = std::dynamic_pointer_cast<ScoreTextDisplayable>(component);
            scoreText->_text = "Score: " + std::to_string(score);
        }
    }
}

const shared::games::components::ComponentsMap &ScoreTextEntity::getComponents(void) const noexcept
{
    return _components;
}
