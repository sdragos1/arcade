/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesProvider
*/

#pragma once

#include "window/NcursesWindow.hpp"
#include "graphics/IGraphicsProvider.hpp"

using namespace shared::graphics;

class NcursesProvider : public IGraphicsProvider {
    public:
        NcursesProvider();
        ~NcursesProvider();

        const shared::graphics::GraphicsManifest &getManifest(void) const noexcept override;
        std::unique_ptr<shared::graphics::IWindow> createWindow(const WindowInitProps &settings) override;
        std::shared_ptr<shared::graphics::ISound> createSound(const std::string &path) override;
        std::shared_ptr<shared::graphics::ITexture> createTexture(const std::string &path) override;
};

static GraphicsManifest NcursesManifest = {
    .name = "ncurses",
    .description = "Ncurses graphics library",
    .version = "1.0.0",
    .authors = {
        {
            .name = "Epitech",
            .email = "dragos.suceveanu@epitech.eu",
            .website = "https://www.epitech.eu"
        }
    }
};
