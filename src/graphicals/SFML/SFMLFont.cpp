/*
** EPITECH PROJECT, 2024
** SFMLFont
** File description:
** Arcade
*/

#include "SFMLFont.hpp"

SFMLFont::SFMLFont(std::string pathFont)
{
    if (!_entitieFont.loadFromFile(pathFont)) {
        std::cerr << "Erreur : Impossible de charger la Font depuis le fichier: ";
        std::cerr << pathFont << std::endl;
        throw std::runtime_error("Can't create SFMLFont class");
    }
    std::cout << "Constructor in SFMLFont" << std::endl;
}

SFMLFont::~SFMLFont()
{
    std::cout << "Destructor in SFMLFont" << std::endl;
}

sf::Font SFMLFont::getFont() const
{
    return _entitieFont;
}
