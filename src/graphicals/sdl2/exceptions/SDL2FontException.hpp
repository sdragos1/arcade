/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SDL2FontException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/IFontException.hpp"

class SDL2FontException : public shared::graphics::exceptions::IFontException
{
    public:
        /**
         * @brief Constructor of SDL2FontException Class
         * @param where
         * @param what
         */
        SDL2FontException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destructor of SDL2FontException Class
         */
        ~SDL2FontException() = default;

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
