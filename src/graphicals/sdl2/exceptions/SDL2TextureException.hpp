/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SDL2TextureException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ITextureException.hpp"

class SDL2TextureException : public shared::graphics::exceptions::ITextureException
{
    public:
        SDL2TextureException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SDL2TextureException() = default;

        const char *where() const noexcept override
        {
            return _where;
        }

        const char* what() const noexcept override
        {
            return _what;
        }

    private:
        const char *_where;
        const char *_what;
};
