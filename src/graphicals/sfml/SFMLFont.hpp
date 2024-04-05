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
#include "exceptions/SFMLFontException.hpp"
#include "../../../common/graphics/IFont.hpp"

class SFMLFont : public shared::graphics::IFont
{
    public:
        /**
         * @brief Construct a new SFMLFont object
         * @param pathFont
         */
        explicit SFMLFont(std::string pathFont);

        /**
         * @brief Destroy the SFMLFont object
         */
        ~SFMLFont();

        /**
         * @brief Get the path to the Font object
         * @return path
         */
        std::string getPath() const;

    private:
        std::string _path;
};
