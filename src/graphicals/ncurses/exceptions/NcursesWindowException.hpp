/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** NcursesWindowException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/IWindowException.hpp"

class NcursesWindowException : public shared::graphics::exceptions::IWindowException
{
    public:
        NcursesWindowException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~NcursesWindowException() = default;

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
