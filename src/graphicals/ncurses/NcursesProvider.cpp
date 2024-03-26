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
NcursesProvider::createWindow(const WindowInitProps &settings)
{
    return std::make_unique<NcursesWindow>(settings);
}

std::shared_ptr<shared::graphics::ISound> NcursesProvider::createSound(const std::string &path)
{
    return nullptr;
}

std::shared_ptr<shared::graphics::ITexture> NcursesProvider::createTexture(const std::string &path)
{
    return nullptr;
}

extern "C" {
    shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
    {
        return shared::types::LibraryType::GRAPHIC;
    }

    std::shared_ptr<shared::graphics::IGraphicsProvider> SHARED_GRAPHICS_PROVIDER_LOADER_NAME(void)
    {
        return std::make_shared<NcursesProvider>();
    }
}
