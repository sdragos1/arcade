/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesTexture
*/

#include "NcursesTexture.hpp"

NcursesTexture::NcursesTexture(const std::string &asciiPath)
{
    std::stringstream buffer;
    std::ifstream file(asciiPath);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << asciiPath << std::endl;
        throw NcursesTextureException("Ncurses Texture", "Can't create Ncurses Texture Class");
    }
    buffer << file.rdbuf();

    _ascii = buffer.str();
}

NcursesTexture::~NcursesTexture()
{
}

const std::string &NcursesTexture::getAscii() const
{
    return _ascii;
}


