/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreText
*/

#include "ScoreText.hpp"

ScoreText::ScoreText(const std::string &content, const shared::games::entity::IEntity &entity)
    : _text(content),
    _props(
        {
            content,
            shared::games::components::ITextComponent::CENTER,
            shared::games::components::ITextComponent::TOP,
            {
                "assets/fonts/arcade.ttf",
                30
            },
            shared::types::Color(0, 0, 255, 255)
        }),
    _size(0, 0),
    _zIndex(2),
    _position(0, 0),
    _entity(entity)
{
}

ScoreText::~ScoreText()
{
}

shared::games::components::ITextComponent::TextProps ScoreText::getTextProps() noexcept
{
    return _props;
}

shared::types::Vector2u &ScoreText::getSize() noexcept
{
    return _size;
}

unsigned int &ScoreText::getZIndex() noexcept
{
    return _zIndex;
}

void ScoreText::onMousePress(std::shared_ptr<shared::games::IGame> &ctx)
{
}

void ScoreText::onMouseRelease(std::shared_ptr<shared::games::IGame> &ctx)
{
}

void ScoreText::onMouseHover(std::shared_ptr<shared::games::IGame> &ctx)
{
}

shared::types::Vector2i &ScoreText::getPosition(void) noexcept
{
    return _position;
}

const shared::games::components::ComponentType ScoreText::getType() const noexcept
{
    return shared::games::components::ComponentType::TEXT;
}

const shared::games::entity::IEntity &ScoreText::getEntity() noexcept
{
    return _entity;
}




