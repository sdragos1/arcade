/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxScore
*/

#include "SolarFoxScore.hpp"

SolarFoxScore::SolarFoxScore()
    : AEntity(), _score(0), _textProps(
            ITextComponent::TextProps{
                std::string("Score: 0"),
                ITextComponent::TextAlign::CENTER,
                ITextComponent::TextVerticalAlign::TOP,
                ITextComponent::TextFontProps{"assets/fonts/Crang.ttf", 20},
                shared::types::Color{255, 255, 255, 255}
            }
    )
{
    std::shared_ptr<TextComponent> textComponent =
        std::make_shared<TextComponent>(
            Vector2f{0, 0}, Vector2u{0, 0}, *this, 0,
            _textProps);

    _components.push_back(textComponent);
}

SolarFoxScore::~SolarFoxScore()
{
}

void SolarFoxScore::increaseScore(std::size_t score)
{
    _score += score;
    _textProps.content = "Score: " + std::to_string(_score);
}

void SolarFoxScore::decreaseScore(std::size_t score)
{
    _score -= score;
    _textProps.content = "Score: " + std::to_string(_score);
}

std::size_t SolarFoxScore::getScore() const
{
    return _score;
}

void SolarFoxScore::resetScore()
{
    _score = 0;
    _textProps.content = "Score: 0";
}
