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
        /**
         * @brief Construct a new SDL2Font object
         * @param pathFont
         */
        explicit SDL2Font(std::string pathFont);

        /**
         * @brief Destroy the SDL2Font object
         */
        ~SDL2Font();

        /**
         * @brief Set the Font object
         * @param characterSize
         */
        void setFont(unsigned int characterSize);

        /**
         * @brief Get the Font object
         * @return TTF_Font*
         */
        TTF_Font* getFont() const;

        /**
         * @brief Set the Surface object
         * @param content
         * @param textColor
         */
        void setSurface(std::string content, SDL_Color textColor);

        /**
         * @brief Get the Surface object
         * @return SDL_Surface*
         */
        SDL_Surface* getSurface() const;

        /**
         * @brief Set the Texture object
         * @param renderer
         */
        void setTexture(SDL_Renderer *renderer);

        /**
         * @brief Get the Texture object
         * @return SDL_Texture*
         */
        SDL_Texture* getTexture() const;

    private:
        std::string     _path;
        TTF_Font*       _font;
        SDL_Surface*    _textSurface;
        SDL_Texture*    _textTexture;
};
