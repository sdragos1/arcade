/*
** EPITECH PROJECT, 2024
** SFMLFont
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../common/graphics/IFont.hpp"

class SFMLFont : public shared::graphics::IFont
{
    public:
        explicit SFMLFont(std::string pathFont);

        ~SFMLFont();

        sf::Font getFont() const;

    private:
        sf::Font _entitieFont;
};
