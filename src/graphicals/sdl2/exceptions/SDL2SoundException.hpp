/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SDL2SoundException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ISoundException.hpp"

class SDL2SoundException : public shared::graphics::exceptions::ISoundException
{
    public:
        SDL2SoundException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        ~SDL2SoundException() = default;

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
