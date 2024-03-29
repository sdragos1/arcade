/*
** EPITECH PROJECT, 2024
** SDL2
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include "SDL2Sound.hpp"
#include "SDL2Texture.hpp"
#include "SDL2Font.hpp"
#include "Window/SDL2Window.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class SDL2 : public shared::graphics::IGraphicsProvider
{
    public:
        SDL2();

        ~SDL2();

        const shared::graphics::GraphicsManifest &getManifest(void) const noexcept override;

        std::unique_ptr<shared::graphics::IWindow> createWindow
        (const shared::graphics::IWindow::WindowInitProps &windowProps) override;

        std::shared_ptr<shared::graphics::ISound> createSound(const std::string &path) override;

        std::shared_ptr<shared::graphics::ITexture> createTexture
        (const std::string &bin, const std::string &ascii) override;

        std::shared_ptr<shared::graphics::IFont> createFont
        (const std::string &path) override;

    private:
        shared::graphics::GraphicsManifest _sdl2Manifest;
};

