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
        NcursesTexture(const std::string &ascii, const std::string &path);
        ~NcursesTexture();

        const std::string &getAscii() const { return _ascii; }
        const std::string &getPath() const { return _path; }
    private:
        std::string _ascii;
        std::string _path;
};
