/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SFMLWindowException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/IWindowException.hpp"

class SFMLWindowException : public shared::graphics::exceptions::IWindowException
{
    public:

        /**
         * @brief Constructor of SFMLWindowException Class
         * @param where
         * @param what
         */
        SFMLWindowException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destructor of SFMLWindowException Class
         */
        ~SFMLWindowException() = default;

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
