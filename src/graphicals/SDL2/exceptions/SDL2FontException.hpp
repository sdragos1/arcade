/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SDL2FontException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/IFontException.hpp"

class SDL2FontException : public shared::graphics::exceptions::IFontException
{
    public:
        SDL2FontException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SDL2FontException() = default;

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
