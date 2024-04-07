/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreTextDisplayable
*/

#include "ScoreTextDisplayable.hpp"

ScoreTextDisplayable::ScoreTextDisplayable(const std::string &content,
    const shared::games::entity::IEntity &entity)
    : _text(content),
    _props(
        {
            ITextComponent::TextProps{
                std::string(content),
                ITextComponent::TextAlign::CENTER,
                ITextComponent::TextVerticalAlign::TOP,
                ITextComponent::TextFontProps{"assets/fonts/Crang.ttf", 20},
                shared::types::Color{255, 255, 255, 255}
            }
        }),
    _size(30, 30),
    _zIndex(2),
    _position(0, 0),
    _entity(entity)
{
}

ScoreTextDisplayable::~ScoreTextDisplayable()
{
}

shared::games::components::ITextComponent::TextProps ScoreTextDisplayable::getTextProps() noexcept
{
    return _props;
}

shared::types::Vector2u &ScoreTextDisplayable::getSize() noexcept
{
    return _size;
}

unsigned int &ScoreTextDisplayable::getZIndex() noexcept
{
    return _zIndex;
}

void ScoreTextDisplayable::onMousePress(std::shared_ptr<shared::games::IGame> ctx)
{
}

void ScoreTextDisplayable::onMouseRelease(std::shared_ptr<shared::games::IGame> ctx)
{
}

void ScoreTextDisplayable::onMouseHover(std::shared_ptr<shared::games::IGame> ctx)
{
}

shared::types::Vector2f &ScoreTextDisplayable::getPosition(void) noexcept
{
    return _position;
}

const shared::games::components::ComponentType ScoreTextDisplayable::getType() const noexcept
{
    return shared::games::components::ComponentType::TEXT;
}

const shared::games::entity::IEntity &ScoreTextDisplayable::getEntity() noexcept
{
    return _entity;
}

void ScoreTextDisplayable::setScore(int score) noexcept
{
    _props.content = "Score: " + std::to_string(score);
}
