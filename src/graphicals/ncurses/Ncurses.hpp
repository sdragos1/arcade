/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** Ncurses
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include "NcursesFont.hpp"
#include "NcursesSound.hpp"
#include "NcursesTexture.hpp"
#include "window/NcursesWindow.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class Ncurses : public shared::graphics::IGraphicsProvider
{
    public:
        Ncurses();
        ~Ncurses();

        const shared::graphics::GraphicsManifest &getManifest(void) const noexcept override;

        std::unique_ptr<shared::graphics::IWindow> createWindow(
        const shared::graphics::IWindow::WindowInitProps &windowProps) override;

        std::shared_ptr<shared::graphics::ISound> createSound(const std::string &path) override;

        std::shared_ptr<shared::graphics::ITexture> createTexture
        (const std::string &path, const std::string &ascii) override;

        std::shared_ptr<IFont> createFont
        (const std::string &path) override;

    private:
        shared::graphics::GraphicsManifest _ncursesManifest;
};
