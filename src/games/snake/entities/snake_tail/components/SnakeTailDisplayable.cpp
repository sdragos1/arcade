/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailDisplayable
*/

#include "SnakeTailDisplayable.hpp"

SnakeTailDisplayable::SnakeTailDisplayable(const entity::IEntity &entity)
    :
    _entity(entity),
    _position({0, 0}),
    _oldPosition({0, 0}),
    _size({1, 1}),
    _zIndex(1),
    _textureProps(
        {
            .sources = {
                .ascii = "<",
                .bin = "/assets/games/snake/tail_left.png",
                .binTileSize = {0, 0}
            },
            .origin = {0, 0}
        }
    )
{
}

SnakeTailDisplayable::~SnakeTailDisplayable()
{
}

const components::ComponentType SnakeTailDisplayable::getType() const noexcept
{
    return components::ComponentType::TEXTURE;
}

const entity::IEntity &SnakeTailDisplayable::getEntity() noexcept
{
    return _entity;
}

Vector2u &SnakeTailDisplayable::getSize(void) noexcept
{
    return _size;
}

unsigned int &SnakeTailDisplayable::getZIndex(void) noexcept
{
    return _zIndex;
}

components::TextureProps &SnakeTailDisplayable::getTextureProps(void) noexcept
{
    return _textureProps;
}

void SnakeTailDisplayable::onMousePress(std::shared_ptr<IGame> &ctx)
{
    (void)ctx;
}

void SnakeTailDisplayable::onMouseHover(std::shared_ptr<IGame> &ctx)
{
    (void)ctx;
}

void SnakeTailDisplayable::onMouseRelease(std::shared_ptr<IGame> &ctx)
{
    (void)ctx;
}

Vector2i &SnakeTailDisplayable::getPosition(void) noexcept
{
    return _position;
}

Vector2i &SnakeTailDisplayable::getOldPosition(void) noexcept
{
    return _oldPosition;
}

void SnakeTailDisplayable::setPosition(Vector2i pos) noexcept
{
    _oldPosition = _position;
    _position = pos;
}