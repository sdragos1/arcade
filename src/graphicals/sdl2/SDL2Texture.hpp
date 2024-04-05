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

        /**
         * @brief Constructor of SDL2Texture Class
         * @param pathTexture
         */
        explicit SDL2Texture(std::string pathTexture);

        /**
         * @brief Destructor of SDL2Texture Class
         */
        ~SDL2Texture();

        /**
         * @brief Get the Path object
         * @param renderer
         */
        void setTexture(SDL_Renderer *renderer);

        /**
         * @brief Get the Texture object
         * @return SDL_Texture*
         */
        SDL_Texture *getTexture() const;

    private:
        std::string     _path;
        SDL_Texture    *_entitieTexture;
};
