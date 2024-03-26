/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#include "NcursesWindow.hpp"

NcursesWindow::NcursesWindow(const WindowInitProps &props)
    : AWindow(props),
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

void NcursesWindow::render(const EntityProps &props)
{
    std::shared_ptr<NcursesTexture> texture = std::dynamic_pointer_cast<NcursesTexture>(props.textureProps.texture);
    std::string ascii = texture->getAscii();
    Vector2u size = props.size;
    Vector2i position = props.position;
    mvwprintw(_window, position.y, position.x, "%s", ascii.c_str());
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

std::vector<events::Event> NcursesWindow::getEvents(void)
{
    int ch = wgetch(_window);

    if (ch != ERR) {
        _events.push_back(NcursesEvents::getNcursesEvent(ch));
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
