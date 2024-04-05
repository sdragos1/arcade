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

        /**
         * @brief Constructor of SDL2 Class
         */
        SDL2();

        /**
         * @brief Destructor of SDL2 Class
         */
        ~SDL2();

        /**
         * @brief Get the Manifest object
         * @return const shared::graphics::GraphicsManifest&
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
        shared::graphics::GraphicsManifest _sdl2Manifest;
};

