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
        /**
         * @brief Construct a new SFMLFontException object
         * @param where
         * @param what
         */
        SFMLFontException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destroy the SFMLFontException object
         */
        ~SFMLFontException() = default;

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
