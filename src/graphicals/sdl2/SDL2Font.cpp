/*
** EPITECH PROJECT, 2024
** SDL2Font
** File description:
** Arcade
*/

#include "SDL2Font.hpp"

SDL2Font::SDL2Font(std::string pathFont)
{
    _path = pathFont;
    _font = nullptr;
    _textSurface = nullptr;
    _textTexture = nullptr;
    std::cout << "Constructor in SDL2Font" << std::endl;
}

SDL2Font::~SDL2Font()
{
    std::cout << "Destructor in SDL2Font" << std::endl;
}

void SDL2Font::setFont(unsigned int characterSize)
{
    if (_font == nullptr) {
        _font = TTF_OpenFont(_path.c_str(), characterSize);
        if (_font == nullptr) {
            throw SDL2FontException("SDL2 Font", "Can't create SDL2 Font");
        }
    }
}

TTF_Font* SDL2Font::getFont() const
{
    return _font;
}


void SDL2Font::setSurface(std::string content, SDL_Color textColor)
{
    if (_textSurface == nullptr) {
        _textSurface = TTF_RenderText_Blended(_font, content.c_str(), textColor);
        if (_textSurface == nullptr) {
            throw SDL2FontException("SDL2 Font", "Can't create SDL2 Font");
        }
    }
}

SDL_Surface* SDL2Font::getSurface() const
{
    return _textSurface;
}


void SDL2Font::setTexture(SDL_Renderer *renderer)
{
    if (_textTexture == nullptr) {
        _textTexture = SDL_CreateTextureFromSurface(renderer, _textSurface);
        if (_textTexture == nullptr) {
            throw SDL2FontException("SDL2 Font", "Can't create SDL2 Font");
        }
    }
}

SDL_Texture* SDL2Font::getTexture() const
{
    return _textTexture;
}

