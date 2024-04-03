/*
** EPITECH PROJECT, 2024
** NcursesFont
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include "../../../common/graphics/IFont.hpp"

class NcursesFont : public shared::graphics::IFont
{
    public:
        explicit NcursesFont(std::string pathFont);
        ~NcursesFont();
};
