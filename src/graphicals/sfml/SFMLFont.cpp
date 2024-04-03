/*
** EPITECH PROJECT, 2024
** SFMLFont
** File description:
** Arcade
*/

#include "SFMLFont.hpp"

SFMLFont::SFMLFont(std::string pathFont)
{
    _path = pathFont;
    // std::cout << "Constructor in SFMLFont" << std::endl;
}

SFMLFont::~SFMLFont()
{
    // std::cout << "Destructor in SFMLFont" << std::endl;
}

std::string SFMLFont::getPath() const
{
    return _path;
}
