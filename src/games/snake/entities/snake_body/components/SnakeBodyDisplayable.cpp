/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeBodyDisplayable
*/

#include "SnakeBodyDisplayable.hpp"

SnakeBodyDisplayable::SnakeBodyDisplayable(const entity::IEntity &entity)
    :
    _entity(entity),
    _position({1, 0}),
    _size({1, 1}),
    _zIndex(1),
    _textureProps(
        {
            .sources = {
                .ascii = "O",
                .bin = "O",
                .binTileSize = {0, 0}
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

void SnakeBodyDisplayable::onMousePress(std::shared_ptr<IGame> &ctx)
{
    (void)ctx;
}

void SnakeBodyDisplayable::onMouseHover(std::shared_ptr<IGame> &ctx)
{
    (void)ctx;
}

void SnakeBodyDisplayable::onMouseRelease(std::shared_ptr<IGame> &ctx)
{
    (void)ctx;
}

Vector2i &SnakeBodyDisplayable::getPosition(void) noexcept
{
    return _position;
}