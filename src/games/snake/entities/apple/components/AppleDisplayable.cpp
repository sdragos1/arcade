/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleDisplayable
*/

#include "AppleDisplayable.hpp"

AppleDisplayable::AppleDisplayable(const shared::games::entity::IEntity &entity)
    :
    _entity(entity),
    _position({20, 20}),
    _size({1, 1}),
    _zIndex(0),
    _textureProps(
        {
            .sources = {
                .ascii = "@",
                .bin = "@",
                .binTileSize = {0, 0}
            },
            .origin = {0, 0}
        }
    )
{
}

AppleDisplayable::~AppleDisplayable()
{
}

const shared::games::components::ComponentType AppleDisplayable::getType() const noexcept
{
    return shared::games::components::ComponentType::TEXTURE;
}

const shared::games::entity::IEntity &AppleDisplayable::getEntity() noexcept
{
    return _entity;
}

Vector2u &AppleDisplayable::getSize(void) noexcept
{
    return _size;
}

unsigned int &AppleDisplayable::getZIndex(void) noexcept
{
    return _zIndex;
}

shared::games::components::TextureProps &AppleDisplayable::getTextureProps(void) noexcept
{
    return _textureProps;
}

void AppleDisplayable::onMousePress(std::shared_ptr<shared::games::IGame> &ctx)
{
    (void)ctx;
}

void AppleDisplayable::onMouseHover(std::shared_ptr<shared::games::IGame> &ctx)
{
    (void)ctx;
}

void AppleDisplayable::onMouseRelease(std::shared_ptr<shared::games::IGame> &ctx)
{
    (void)ctx;
}

Vector2i &AppleDisplayable::getPosition(void) noexcept
{
    return _position;
}