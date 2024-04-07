/*
** EPITECH PROJECT, 2024
** SFMLTexture
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "exceptions/SFMLTextureException.hpp"
#include "../../../common/graphics/ITexture.hpp"

class SFMLTexture : public shared::graphics::ITexture
{
    public:
        /**
         * @brief Construct a new SFMLTexture object
         * @param pathTexture
         */
        explicit SFMLTexture(std::string pathTexture);

        /**
         * @brief Destroy the SFMLTexture object
         */
        ~SFMLTexture();

        /**
         * @brief Get the texture
         * @return sf::Texture
         */
        sf::Texture getTexture() const;

    private:
        sf::Texture _entitieTexture;
};
