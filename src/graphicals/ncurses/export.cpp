/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** export
*/

#include "types/Libraries.hpp"
#include "NcursesProvider.hpp"

extern "C" {
    shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
    {
        return shared::types::LibraryType::GRAPHIC;
    }

    shared::graphics::IGraphicsProvider *SHARED_GRAPHICS_PROVIDER_GETTER_NAME(void)
    {
        return new NcursesProvider();
    }
}

