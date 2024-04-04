/*
** EPITECH PROJECT, 2024
** SDL2Texture
** File description:
** Arcade
*/

#include "SDL2Texture.hpp"

SDL2Texture::SDL2Texture(std::string pathTexture)
{
    _path = pathTexture;
    _entitieTexture = nullptr;
}

SDL2Texture::~SDL2Texture()
{
}

void SDL2Texture::setTexture(SDL_Renderer *renderer)
{
    if (_entitieTexture == nullptr) {
        _entitieTexture = IMG_LoadTexture(renderer, _path.c_str());
        if (_entitieTexture == nullptr) {
            throw SDL2TextureException("SLD2 Texture", "Can't create Texture");
        }
    }
}

SDL_Texture *SDL2Texture::getTexture() const
{
    return _entitieTexture;
}
