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
        /**
         * @brief Constructor of SDL2SoundException Class
         * @param where
         * @param what
         */
        SDL2SoundException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destructor of SDL2SoundException Class
         */
        ~SDL2SoundException() = default;

        /**
         * @brief Get the where object
         * @return const char*
         */
        const char *where() const noexcept override
        {
            return _where;
        }

        /**
         * @brief Get the what object
         * @return const char*
         */
        const char* what() const noexcept override
        {
            return _what;
        }

    private:
        const char *_where;
        const char *_what;
};
