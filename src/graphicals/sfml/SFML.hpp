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
#include "SFMLFont.hpp"
#include "SFMLSound.hpp"
#include "SFMLTexture.hpp"
#include "Window/SFMLWindow.hpp"
#include "../../../common/types/Libraries.hpp"
#include "../../../common/graphics/IGraphicsProvider.hpp"

class SFML : public shared::graphics::IGraphicsProvider
{
    public:
        /**
         * @brief Construct a new SFML object
         */
        SFML();

        /**
         * @brief Destroy the SFML object
         */
        ~SFML();

        /**
         * @brief Get the Manifest object
         * @return shared::graphics::GraphicsManifest
         */
        const shared::graphics::GraphicsManifest &getManifest(void) const noexcept override;

        /**
         * @brief Create a Window object
         * @param windowProps
         * @return std::unique_ptr<shared::graphics::IWindow>
         */
        std::unique_ptr<shared::graphics::IWindow> createWindow
        (const shared::graphics::IWindow::WindowInitProps &windowProps) override;

        /**
         * @brief Create a Sound object
         * @param path
         * @return std::shared_ptr<shared::graphics::ISound>
         */
        std::shared_ptr<shared::graphics::ISound> createSound(const std::string &path) override;

        /**
         * @brief Create a Texture object
         * @param bin
         * @param ascii
         * @return std::shared_ptr<shared::graphics::ITexture>
         */
        std::shared_ptr<shared::graphics::ITexture> createTexture
        (const std::string &bin, const std::string &ascii) override;

        /**
         * @brief Create a Font object
         * @param path
         * @return std::shared_ptr<shared::graphics::IFont>
         */
        std::shared_ptr<shared::graphics::IFont> createFont
        (const std::string &path) override;

    private:
        shared::graphics::GraphicsManifest _sfmlManifest;
};

