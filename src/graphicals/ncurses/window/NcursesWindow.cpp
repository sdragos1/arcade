/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#include "NcursesWindow.hpp"

NcursesWindow::NcursesWindow(const WindowInitProps &props)
    : _title(props.title), _size(props.size), _mode(props.mode), _icon(props.icon),_fps(60), _isOpen(true)
{
    _window = initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
}

NcursesWindow::~NcursesWindow()
{
}

void NcursesWindow::setTitle(const std::string &title)
{
    _title = title;
}

std::string NcursesWindow::getTitle() const
{
    return _title;
}

void NcursesWindow::setSize(Vector2u size)
{
    _size = size;
}

Vector2u NcursesWindow::getSize() const
{
    return _size;
}

void NcursesWindow::setFramerateLimit(unsigned int limit)
{
    _fps = limit;
}

unsigned int NcursesWindow::getFramerateLimit() const
{
    return _fps;
}

void NcursesWindow::setMode(WindowMode mode)
{
    _mode = mode;
}

WindowMode NcursesWindow::getMode() const
{
    return _mode;
}

void NcursesWindow::setIcon(const std::string &icon)
{
    _icon = icon;
}

const std::string &NcursesWindow::getIcon(void) const
{
    return _icon;
}

void NcursesWindow::render(const EntityProps &props)
{
    (void)props;
}

void NcursesWindow::clear()
{
}

void NcursesWindow::display()
{
}

void NcursesWindow::close()
{
    _isOpen = false;
}

bool NcursesWindow::isOpen() const
{
    return _isOpen;
}

std::vector<events::IEvent> NcursesWindow::getEvents(void)
{
    return std::vector<events::IEvent>();
}
