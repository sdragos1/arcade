/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadDisplayable
*/

#include "SnakeHeadDisplayable.hpp"

SnakeHeadDisplayable::SnakeHeadDisplayable(const entity::IEntity &entity)
    :
    _entity(entity),
    _position({17, 9}),
    _oldPosition({17, 9}),
    _size({1, 1}),
    _zIndex(1),
    _textureProps(
        {
            .sources = {
                .ascii = "$",
                .bin = "assets/games/snake/snake.png",
                .binTileSize = {1, 1}
            },
            .origin = {0, 0}
        }
    )
{
}

SnakeHeadDisplayable::~SnakeHeadDisplayable()
{
}

const components::ComponentType SnakeHeadDisplayable::getType() const noexcept
{
    return components::ComponentType::TEXTURE;
}

const entity::IEntity &SnakeHeadDisplayable::getEntity() noexcept
{
    return _entity;
}

Vector2u &SnakeHeadDisplayable::getSize(void) noexcept
{
    return _size;
}

unsigned int &SnakeHeadDisplayable::getZIndex(void) noexcept
{
    return _zIndex;
}

components::TextureProps &SnakeHeadDisplayable::getTextureProps(void) noexcept
{
    return _textureProps;
}

void SnakeHeadDisplayable::onMousePress(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void SnakeHeadDisplayable::onMouseHover(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void SnakeHeadDisplayable::onMouseRelease(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

Vector2i &SnakeHeadDisplayable::getPosition(void) noexcept
{
    return _position;
}

Vector2i &SnakeHeadDisplayable::getOldPosition(void) noexcept
{
    return _oldPosition;
}

void SnakeHeadDisplayable::setPosition(Vector2i pos) noexcept
{
    _oldPosition = _position;
    _position = pos;
}

void SnakeHeadDisplayable::setOldPosition(Vector2i pos) noexcept
{
    _oldPosition = pos;
}