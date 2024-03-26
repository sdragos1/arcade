/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#include "NcursesWindow.hpp"

NcursesWindow::NcursesWindow(const WindowInitProps &props)
    : _title(props.title),
        _size(props.size),
        _mode(props.mode),
        _icon(props.icon),
        _fps(60),
        _isOpen(true),
        _events()
{
    _window = initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    nodelay(_window, true);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
}

NcursesWindow::~NcursesWindow()
{
    delwin(_window);
    endwin();
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
    werase(_window);
}

void NcursesWindow::display()
{
    renderTitle();
    wrefresh(_window);
}

void NcursesWindow::close()
{
    endwin();
}

bool NcursesWindow::isOpen() const
{
    return _isOpen;
}

std::vector<events::Event> NcursesWindow::getEvents(void)
{
    int ch = wgetch(_window);

    if (ch != ERR) {
        switch (ch) {
            case KEY_UP: {
                _events.push_back(events::KeyPressEvent(events::KeyType::ARROW, events::KeyCode{.arrow = events::ArrowCode::UP}));
                break;
            }
            case KEY_DOWN:
                _events.push_back(events::KeyPressEvent(events::KeyType::ARROW, events::KeyCode{.arrow = events::ArrowCode::DOWN}));
                break;
            case KEY_LEFT:
                _events.push_back(events::KeyPressEvent(events::KeyType::ARROW, events::KeyCode{.arrow = events::ArrowCode::LEFT}));
                break;
            case KEY_RIGHT:
                _events.push_back(events::KeyPressEvent(events::KeyType::ARROW, events::KeyCode{.arrow = events::ArrowCode::RIGHT}));
                break;
            default:
                break;
        }
    }
    return _events;
}

void NcursesWindow::renderTitle() const
{
    int titleLength = _title.length();
    int windowWidth = getmaxx(_window);
    int titleX = (windowWidth - titleLength) / 2;
    mvwprintw(_window, 0, titleX, "%s", _title.c_str());
}
