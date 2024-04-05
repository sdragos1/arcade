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

        /**
         * @brief Construct a new SFMLSoundException object
         * @param where
         * @param what
         */
        SFMLSoundException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destroy the SFMLSoundException object
         */
        ~SFMLSoundException() = default;

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
