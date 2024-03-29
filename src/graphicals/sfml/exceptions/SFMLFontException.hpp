/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SFMLFontException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/IFontException.hpp"

class SFMLFontException : public shared::graphics::exceptions::IFontException
{
    public:
        SFMLFontException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SFMLFontException() = default;

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
