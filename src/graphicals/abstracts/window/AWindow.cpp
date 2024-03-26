/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AWindow
*/

#include "AWindow.hpp"

AWindow::AWindow(const shared::graphics::WindowInitProps &props)
    : _title(props.title),
    _size(props.size),
    _mode(props.mode),
    _icon(props.icon),
    _fps(props.fps),
    _isOpen(false)
{
}

AWindow::~AWindow()
{
}

void AWindow::setTitle(const std::string &title)
{
    _title = title;
}

std::string AWindow::getTitle() const
{
    return _title;
}

void AWindow::setSize(Vector2u size)
{
    _size = size;
}

Vector2u AWindow::getSize() const
{
    return _size;
}

void AWindow::setFramerateLimit(unsigned int framerate)
{
    _fps = framerate;
}

unsigned int AWindow::getFramerateLimit() const
{
    return _fps;
}

void AWindow::setMode(shared::graphics::WindowMode mode)
{
    _mode = mode;
}

shared::graphics::WindowMode AWindow::getMode() const
{
    return _mode;
}

void AWindow::setIcon(const std::string &icon)
{
    _icon = icon;
}

bool AWindow::isOpen(void) const
{
    return _isOpen;
}

const std::string &AWindow::getIcon() const
{
    return _icon;
}
