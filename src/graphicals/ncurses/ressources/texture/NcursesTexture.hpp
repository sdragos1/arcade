/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesTexture
*/

#pragma once

#include <string>
#include "graphics/ITexture.hpp"

class NcursesTexture : public shared::graphics::ITexture {
    public:
        NcursesTexture(const std::string &ascii);
        ~NcursesTexture();

        const std::string &getAscii() const { return _ascii; }
    private:
        std::string _ascii;
};
