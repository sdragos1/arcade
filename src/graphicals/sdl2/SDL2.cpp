/*
** EPITECH PROJECT, 2024
** SDL2
** File description:
** Arcade
*/

#include "SDL2.hpp"

SDL2::SDL2() : _sdl2Manifest{"SDL2", "SDL2 Library", "2.30.1", {{"Sam Lantiga", "none", "none"}}}
{
    std::cout << "Constructor in SDL2" << std::endl;
}

SDL2::~SDL2()
{
    std::cout << "Destructor in SDL2" << std::endl;
}

const shared::graphics::GraphicsManifest &SDL2::getManifest(void) const noexcept
{
    return _sdl2Manifest;
}

std::unique_ptr<shared::graphics::IWindow> SDL2::createWindow
(const shared::graphics::IWindow::WindowInitProps &windowProps)
{
    return std::make_unique<SDL2Window>(windowProps);
}

std::shared_ptr<shared::graphics::ISound> SDL2::createSound(const std::string &path)
{
    return std::make_shared<SDL2Sound>(path);
}

std::shared_ptr<shared::graphics::ITexture> SDL2::createTexture
(const std::string &bin, const std::string &ascii)
{
    return std::make_shared<SDL2Texture>(bin);
}

std::shared_ptr<shared::graphics::IFont> SDL2::createFont(const std::string &path)
{
    return std::make_shared<SDL2Font>(path);
}

extern "C" shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME()
{
    return shared::types::LibraryType::GRAPHIC;
}

extern "C" shared::graphics::IGraphicsProvider *
SHARED_GRAPHICS_PROVIDER_GETTER_NAME(void)
{
    return new SDL2();
}
