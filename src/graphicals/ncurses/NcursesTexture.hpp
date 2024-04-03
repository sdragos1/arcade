/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesTexture
*/

#pragma once

#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "exceptions/NcursesTextureException.hpp"
#include "../../../common/graphics/ITexture.hpp"

class NcursesTexture : public shared::graphics::ITexture
{
    public:
        explicit NcursesTexture(const std::string &asciiPath);

        ~NcursesTexture();

        const std::string &getAscii() const;

    private:
        std::string _ascii;
};
