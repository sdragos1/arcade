/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** HighScoreTextEntity
*/

#include "HighScoreTextEntity.hpp"

HighScoreTextEntity::HighScoreTextEntity()
    : _components()
{
    std::shared_ptr<HighScoreTextDisplayable> scoreText = getHighScores();
    _components.push_back(scoreText);
}

HighScoreTextEntity::~HighScoreTextEntity()
{
}

const shared::games::components::ComponentsMap &HighScoreTextEntity::getComponents(void) const noexcept
{
    return _components;
}

std::shared_ptr<HighScoreTextDisplayable> HighScoreTextEntity::getHighScores(void) const noexcept
{
    std::ifstream file("scores/SnakeHighScore.abd");
    std::string line;
    std::string content = "HighScore:";
    if (file.is_open()) {
        while (std::getline(file, line)) {
            content += line;
        }
        file.close();
    }
    return std::make_shared<HighScoreTextDisplayable>(content, *this);
}