/*
** EPITECH PROJECT, 2024
** SFMLTexture
** File description:
** Arcade
*/

#include "SFMLTexture.hpp"

SFMLTexture::SFMLTexture(std::string pathTexture)
{
    if (!_entitieTexture.loadFromFile(pathTexture)) {
        std::cerr << "Erreur : Impossible de charger la texture depuis le fichier: ";
        std::cerr << pathTexture << std::endl;
        throw SFMLTextureException("SFML Texture", "Can't create SFML Texture Class");
    }
}

SFMLTexture::~SFMLTexture()
{
}

sf::Texture SFMLTexture::getTexture() const
{
    return _entitieTexture;
}
