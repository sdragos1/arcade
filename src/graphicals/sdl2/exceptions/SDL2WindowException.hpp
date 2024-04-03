/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SDL2WindowException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/IWindowException.hpp"

class SDL2WindowException : public shared::graphics::exceptions::IWindowException
{
    public:
        SDL2WindowException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SDL2WindowException() = default;

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
