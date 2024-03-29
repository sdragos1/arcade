/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SFMLSoundException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ISoundException.hpp"

class SFMLSoundException : public shared::graphics::exceptions::ISoundException
{
    public:
        SFMLSoundException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SFMLSoundException() = default;

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
