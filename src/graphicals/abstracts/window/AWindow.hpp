/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AWindow
*/

#pragma once

#include "graphics/IWindow.hpp"

class AWindow : public shared::graphics::IWindow {
    public:
        explicit AWindow(const shared::graphics::IWindow::WindowInitProps &props);
        ~AWindow();

        void setTitle(const std::string &title) override;
        void setSize(Vector2u size) override;
        Vector2u getSize() const override;
        void setFramerateLimit(unsigned int framerate) override;
        unsigned int getFramerateLimit() const override;
        void setMode(shared::graphics::IWindow::WindowMode mode) override;
        shared::graphics::IWindow::WindowMode getMode() const override;
        void setIcon(const std::string &icon) override;
        bool isOpen(void) const override;

    protected:
        std::string _title;
        Vector2u _size;
        shared::graphics::IWindow::WindowMode _mode;
        std::string _icon;
        unsigned int _fps;
        bool _isOpen;
};
