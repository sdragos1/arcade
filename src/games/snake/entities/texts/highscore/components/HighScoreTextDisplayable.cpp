/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** HighScoreTextDisplayable
*/

#include "HighScoreTextDisplayable.hpp"

HighScoreTextDisplayable::HighScoreTextDisplayable(const std::string &content, const shared::games::entity::IEntity &entity)
    : _text(content),
    _props(
        {
            content,
            shared::games::components::ITextComponent::LEFT,
            shared::games::components::ITextComponent::TOP,
            {
                "assets/fonts/upheavtt.ttf",
                30
            },
            shared::types::Color(0, 0, 0, 0)
        }),
    _size(5, 5),
    _zIndex(2),
    _position(0, 0),
    _entity(entity)
{
}

HighScoreTextDisplayable::~HighScoreTextDisplayable()
{
}

shared::games::components::ITextComponent::TextProps HighScoreTextDisplayable::getTextProps() noexcept
{
    return _props;
}

shared::types::Vector2u &HighScoreTextDisplayable::getSize() noexcept
{
    return _size;
}

unsigned int &HighScoreTextDisplayable::getZIndex() noexcept
{
    return _zIndex;
}

void HighScoreTextDisplayable::onMousePress(std::shared_ptr<shared::games::IGame> ctx)
{
}

void HighScoreTextDisplayable::onMouseRelease(std::shared_ptr<shared::games::IGame> ctx)
{
}

void HighScoreTextDisplayable::onMouseHover(std::shared_ptr<shared::games::IGame> ctx)
{
}

shared::types::Vector2f &HighScoreTextDisplayable::getPosition(void) noexcept
{
    return _position;
}

const shared::games::components::ComponentType HighScoreTextDisplayable::getType() const noexcept
{
    return shared::games::components::ComponentType::TEXT;
}

const shared::games::entity::IEntity &HighScoreTextDisplayable::getEntity() noexcept
{
    return _entity;
}