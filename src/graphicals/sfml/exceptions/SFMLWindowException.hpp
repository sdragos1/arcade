/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SFMLWindowException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ITextureException.hpp"

class SFMLWindowException : public shared::graphics::exceptions::ITextureException
{
    public:
        SFMLWindowException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SFMLWindowException() = default;

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
