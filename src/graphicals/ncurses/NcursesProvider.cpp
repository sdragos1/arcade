/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesProvider
*/

#include "types/Libraries.hpp"
#include "NcursesProvider.hpp"

NcursesProvider::NcursesProvider()
{
}

NcursesProvider::~NcursesProvider()
{
}

const shared::graphics::GraphicsManifest &NcursesProvider::getManifest(void) const noexcept
{
    return NcursesManifest;
}

std::unique_ptr<shared::graphics::IWindow>
NcursesProvider::createWindow(const shared::graphics::IWindow::WindowInitProps &settings)
{
    return std::make_unique<NcursesWindow>(settings);
}

std::shared_ptr<shared::graphics::ISound> NcursesProvider::createSound(const std::string &path)
{
    return nullptr;
}

std::shared_ptr<shared::graphics::ITexture> NcursesProvider::createTexture(const std::string &path,
const std::string &ascii)
{
    return std::make_shared<NcursesTexture>(ascii, path);
}

std::shared_ptr<IFont> NcursesProvider::createFont(const std::string &path)
{
    return std::make_shared<NcursesFont>();
}
