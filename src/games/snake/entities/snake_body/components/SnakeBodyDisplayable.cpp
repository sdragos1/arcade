/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyDisplayable
*/

#include "SnakeBodyDisplayable.hpp"

SnakeBodyDisplayable::SnakeBodyDisplayable(const entity::IEntity &entity, Vector2f position)
    :
    _entity(entity),
    _position(position),
    _oldPosition(position),
    _size({1, 1}),
    _zIndex(2),
    _textureProps(
        {
            .sources = {
                .ascii = "assets/snake/snake.txt",
                .bin = "assets/snake/snake.png",
                .binTileSize = {40, 40}
            },
            .origin = {0, 0}
        }
    )
{
}

SnakeBodyDisplayable::~SnakeBodyDisplayable()
{
}

const components::ComponentType SnakeBodyDisplayable::getType() const noexcept
{
    return components::ComponentType::TEXTURE;
}

const entity::IEntity &SnakeBodyDisplayable::getEntity() noexcept
{
    return _entity;
}

Vector2u &SnakeBodyDisplayable::getSize(void) noexcept
{
    return _size;
}

unsigned int &SnakeBodyDisplayable::getZIndex(void) noexcept
{
    return _zIndex;
}

components::TextureProps &SnakeBodyDisplayable::getTextureProps(void) noexcept
{
    return _textureProps;
}

void SnakeBodyDisplayable::onMousePress(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void SnakeBodyDisplayable::onMouseHover(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void SnakeBodyDisplayable::onMouseRelease(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

Vector2f &SnakeBodyDisplayable::getPosition(void) noexcept
{
    return _position;
}

Vector2f &SnakeBodyDisplayable::getOldPosition(void) noexcept
{
    return _oldPosition;
}

void SnakeBodyDisplayable::setPosition(Vector2f pos) noexcept
{
    _position = pos;
}

void SnakeBodyDisplayable::setOldPosition(Vector2f pos) noexcept
{
    _oldPosition = pos;
}
