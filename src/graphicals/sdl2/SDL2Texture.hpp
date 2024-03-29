/*
** EPITECH PROJECT, 2024
** SDL2Texture
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "exceptions/SDL2TextureException.hpp"
#include "../../../common/graphics/ITexture.hpp"

class SDL2Texture : public shared::graphics::ITexture
{
    public:
        explicit SDL2Texture(std::string pathTexture);

        ~SDL2Texture();

        void setTexture(SDL_Renderer *renderer);

        SDL_Texture *getTexture() const;

    private:
        std::string     _path;
        SDL_Texture    *_entitieTexture;
};
