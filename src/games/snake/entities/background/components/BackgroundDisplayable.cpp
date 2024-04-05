/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** BackgroundDisplayable
*/

#include "BackgroundDisplayable.hpp"

BackgroundDisplayable::BackgroundDisplayable(const shared::games::entity::IEntity &entity)
    :
    _entity(entity),
    _position({0, 0}),
    _size({32, 18}),
    _zIndex(10),
    _textureProps(
        {
            .sources = {
                .ascii = "",
                .bin = "assets/snake/background.png",
                .binTileSize = {40, 40}
            },
            .origin = {0, 0}
        }
    )
{
}

BackgroundDisplayable::~BackgroundDisplayable()
{
}

const shared::games::components::ComponentType BackgroundDisplayable::getType() const noexcept
{
    return shared::games::components::ComponentType::TEXTURE;
}

const shared::games::entity::IEntity &BackgroundDisplayable::getEntity() noexcept
{
    return _entity;
}

Vector2u &BackgroundDisplayable::getSize(void) noexcept
{
    return _size;
}

unsigned int &BackgroundDisplayable::getZIndex(void) noexcept
{
    return _zIndex;
}

shared::games::components::TextureProps &BackgroundDisplayable::getTextureProps(void) noexcept
{
    return _textureProps;
}

void BackgroundDisplayable::onMousePress(std::shared_ptr<shared::games::IGame> ctx)
{
    (void)ctx;
}

void BackgroundDisplayable::onMouseHover(std::shared_ptr<shared::games::IGame> ctx)
{
    (void)ctx;
}

void BackgroundDisplayable::onMouseRelease(std::shared_ptr<shared::games::IGame> ctx)
{
    (void)ctx;
}

Vector2f &BackgroundDisplayable::getPosition(void) noexcept
{
    return _position;
}