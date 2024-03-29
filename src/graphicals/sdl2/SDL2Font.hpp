/*
** EPITECH PROJECT, 2024
** SDL2Font
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../../../common/graphics/IFont.hpp"
#include "exceptions/SDL2FontException.hpp"

class SDL2Font : public shared::graphics::IFont
{
    public:
        explicit SDL2Font(std::string pathFont);

        ~SDL2Font();

        void setFont(unsigned int characterSize);
        TTF_Font* getFont() const;

        void setSurface(std::string content, SDL_Color textColor);
        SDL_Surface* getSurface() const;

        void setTexture(SDL_Renderer *renderer);
        SDL_Texture* getTexture() const;

    private:
        std::string     _path;
        TTF_Font*       _font;
        SDL_Surface*    _textSurface;
        SDL_Texture*    _textTexture;
};
