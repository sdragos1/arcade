/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** NcursesTextureException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ITextureException.hpp"

class NcursesTextureException : public shared::graphics::exceptions::ITextureException
{
    public:
        NcursesTextureException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~NcursesTextureException() = default;

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
