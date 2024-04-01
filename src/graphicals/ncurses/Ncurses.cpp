/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include "types/Libraries.hpp"

Ncurses::Ncurses() :
_ncursesManifest{"NCURSES", "NCURSES Library", "6.4 ", {{"Thomas Dickey", "none", "none"}}}
{
}

Ncurses::~Ncurses()
{
}

const shared::graphics::GraphicsManifest &Ncurses::getManifest(void) const noexcept
{
    return _ncursesManifest;
}

std::unique_ptr<shared::graphics::IWindow>
Ncurses::createWindow(const shared::graphics::IWindow::WindowInitProps &settings)
{
    return std::make_unique<NcursesWindow>(settings);
}

std::shared_ptr<shared::graphics::ISound> Ncurses::createSound(const std::string &path)
{
    return std::make_shared<NcursesSound>(path);
}

std::shared_ptr<shared::graphics::ITexture> Ncurses::createTexture(const std::string &path,
const std::string &ascii)
{
    return std::make_shared<NcursesTexture>(ascii);
}

std::shared_ptr<IFont> Ncurses::createFont(const std::string &path)
{
    return std::make_shared<NcursesFont>(path);
}

extern "C" shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME()
{
    return shared::types::LibraryType::GRAPHIC;
}

extern "C" shared::graphics::IGraphicsProvider *
SHARED_GRAPHICS_PROVIDER_GETTER_NAME(void)
{
    return new Ncurses();
}
