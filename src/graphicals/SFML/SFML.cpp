/*
** EPITECH PROJECT, 2024
** SFML
** File description:
** Arcade
*/

#include "SFML.hpp"

SFML::SFML() : _sfmlManifest{"SFML", "SFML Library", "2.6.1", {{"Laurent Gomila", "none", "none"}}}
{
    std::cout << "Constructor in SFML" << std::endl;
}

SFML::~SFML()
{
    std::cout << "Destructor in SFML" << std::endl;
}

const shared::graphics::GraphicsManifest &SFML::getManifest(void) const noexcept
{
    return _sfmlManifest;
}

std::unique_ptr<shared::graphics::IWindow> SFML::createWindow
(const shared::graphics::IWindow::WindowInitProps &windowProps)
{
    return std::make_unique<SFMLWindow>(windowProps);
}

std::shared_ptr<shared::graphics::ISound> SFML::createSound(const std::string &path)
{
    return std::make_shared<SFMLSound>(path);
}

std::shared_ptr<shared::graphics::ITexture> SFML::createTexture
(const std::string &bin, const std::string &ascii)
{
    return std::make_shared<SFMLTexture>(bin);
}

std::shared_ptr<shared::graphics::IFont> SFML::createFont(const std::string &path)
{
    return std::make_shared<SFMLFont>(path);
}

extern "C" shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME()
{
    return shared::types::LibraryType::GRAPHIC;
}

extern "C" shared::graphics::IGraphicsProvider *
SHARED_GRAPHICS_PROVIDER_GETTER_NAME(void)
{
    return new SFML();
}
