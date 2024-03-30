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
        explicit SFMLTexture(std::string pathTexture);

        ~SFMLTexture();

        sf::Texture getTexture() const;

    private:
        sf::Texture _entitieTexture;
};
