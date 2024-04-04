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
}

SFMLFont::~SFMLFont()
{
}

std::string SFMLFont::getPath() const
{
    return _path;
}
