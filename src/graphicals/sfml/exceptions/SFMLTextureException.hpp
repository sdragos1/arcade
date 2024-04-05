/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SFMLTextureException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ITextureException.hpp"

class SFMLTextureException : public shared::graphics::exceptions::ITextureException
{
    public:
        /**
         * @brief Construct a new SFMLTextureException object
         * @param where
         * @param what
         */
        SFMLTextureException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destroy the SFMLTextureException object
         */
        ~SFMLTextureException() = default;

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
