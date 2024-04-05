/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** SDL2TextureException.hpp
*/

#pragma once

#include <string>
#include "../../../../common/graphics/exceptions/ITextureException.hpp"

class SDL2TextureException : public shared::graphics::exceptions::ITextureException
{
    public:

        /**
         * @brief Constructor of SDL2TextureException Class
         * @param where
         * @param what
         */
        SDL2TextureException(const char *where, const char *what)
        {
            _where = where;
            _what = what;
        }

        /**
         * @brief Destructor of SDL2TextureException Class
         */
        ~SDL2TextureException() = default;

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
