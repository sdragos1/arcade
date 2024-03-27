/*
** EPITECH PROJECT, 2024
** SFML
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLTexture.hpp"
#include "SFMLSound.hpp"
#include "Window/SFMLWindow.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class SFML : public shared::graphics::IGraphicsProvider
{
    public:
        SFML();

        ~SFML();

        const shared::graphics::GraphicsManifest &getManifest(void) const noexcept override;

        std::unique_ptr<shared::graphics::IWindow> createWindow
        (const shared::graphics::IWindow::WindowInitProps &windowProps) override;

        std::shared_ptr<shared::graphics::ISound> createSound(const std::string &path) override;

        std::shared_ptr<shared::graphics::ITexture> createTexture
        (const std::string &bin, const std::string &ascii) override;

    private:
        shared::graphics::GraphicsManifest _sfmlManifest;
};

