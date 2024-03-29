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

void NcursesWindow::render(const TextureProps &props)
{
    std::shared_ptr<NcursesTexture> texture =
        std::dynamic_pointer_cast<NcursesTexture>(props.texture);
    std::string ascii = texture->getAscii();
    Vector2u size = props.size;
    Vector2i position = props.position;

    mvwprintw(_window, position.y + NCURSES_ORIGIN_OFFSET, position.x, "%s", ascii.c_str());
}

void NcursesWindow::render(const TextProps &props)
{
    std::string text = props.content;
    Vector2i position = props.position;
    int start_y = 0;
    int start_x = 0;

    switch (props.verticalAlign) {
        case TextVerticalAlign::TOP:
            start_y = NCURSES_ORIGIN_OFFSET;
            break;
        case TextVerticalAlign::MIDDLE:
            start_y = getmaxy(_window) / 2;
            break;
        case TextVerticalAlign::BOTTOM:
            start_y = getmaxy(_window) - 1;
            break;
    }
    switch (props.align) {
        case TextAlign::LEFT:
            break;
        case TextAlign::CENTER:
            start_x = (getmaxx(_window) - text.length()) / 2;
            break;
        case TextAlign::RIGHT:
            start_x = getmaxx(_window) - text.length();
            break;
    }
    wattron(_window, getNcursesColor(props.color));
    mvwprintw(_window, start_y + position.y, start_x + position.x, "%s", text.c_str());
    wattroff(_window, getNcursesColor(props.color));
}

void NcursesWindow::clear()
{
    wrefresh(_window);
    werase(_window);
}

void NcursesWindow::display()
{
    renderTitle();
}

void NcursesWindow::close()
{
    endwin();
}

std::vector<events::EventPtr> NcursesWindow::getEvents()
{
    std::vector<events::EventPtr> eventsList;
    events::IKeyEvent::KeyType keyType;
    int ch;

    while ((ch = getch()) != ERR) {
        keyType = NcursesEvents::mapNcursesKeyToKeyType(ch);
        if (keyType != events::IKeyEvent::UNKNOWN) {
            eventsList.push_back(std::make_shared<events::KeyPressedEvent>(
                keyType, NcursesEvents::mapNcursesKeyToKeyCode(ch, keyType)));
        }
    }

    return eventsList;
}

void NcursesWindow::renderTitle() const
{
        int titleLength = _title.length();
        int windowWidth = getmaxx(_window);
        if (titleLength >= windowWidth) {
            mvwprintw(_window, 0, 0, "Error: Title too long");
            return;
        }
        int titleX = (windowWidth - titleLength) / 2;
        wattron(_window, A_BOLD | COLOR_PAIR(1));
        mvwprintw(_window, 0, titleX, "%s", _title.c_str());
        wattroff(_window, A_BOLD | COLOR_PAIR(1));
        int padding = 2;
        for (int i = 0; i < padding; ++i) {
            mvwprintw(_window, 0, titleX - i - 1, " ");
            mvwprintw(_window, 0, titleX + titleLength + i, " ");
        }
        wattron(_window, A_ALTCHARSET);
        mvwhline(_window, 0, 1, ACS_HLINE, windowWidth);
        wattroff(_window, A_ALTCHARSET);
}

int16_t NcursesWindow::getNcursesColor(const shared::types::Color &color) const
{
    int r = static_cast<int>(color.r);
    int g = static_cast<int>(color.g);
    int b = static_cast<int>(color.b);

    int colorIndex = (r * 6 / 256) * 36 + (g * 6 / 256) * 6 + (b * 6 / 256) + 16;
    return COLOR_PAIR(colorIndex);
}
