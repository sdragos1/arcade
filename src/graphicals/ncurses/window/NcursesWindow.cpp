/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#include "NcursesWindow.hpp"

NcursesWindow::NcursesWindow(const WindowInitProps &windowProps) :
_ncursesbasicwindow(windowProps.size)
{
    _running = true;
    _window = initscr();
    if (_window == NULL)
        throw std::runtime_error("Error: initscr failed");
    cbreak();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_color(COLOR_WHITE, 1000, 1000, 1000);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    _title = windowProps.title;
    _mode = windowProps.mode;

    std::cout << "Ncurses window created" << std::endl;
}

NcursesWindow::~NcursesWindow()
{
    std::cout << "Ncurses window destroyed" << std::endl;
    endwin();
}

void NcursesWindow::setTitle(const std::string &title)
{
    _title = title;
}

void NcursesWindow::setSize(Vector2u size)
{
}

Vector2u NcursesWindow::getSize() const
{
    int width = 0;
    int height = 0;
    getmaxyx(stdscr, height, width);
    return ((Vector2u) {static_cast<unsigned int>(width), static_cast<unsigned int>(height)});
}

void NcursesWindow::setFramerateLimit(unsigned int fps)
{
    _fps = fps;
}

unsigned int NcursesWindow::getFramerateLimit() const
{
    return _fps;
}

void NcursesWindow::setMode(shared::graphics::IWindow::WindowMode mode)
{
    _mode = mode;
}

shared::graphics::IWindow::WindowMode NcursesWindow::getMode(void) const
{
    return _mode;
}

void NcursesWindow::setIcon(const std::string &icon)
{
}

void NcursesWindow::render(const TextureProps &props)
{
    std::shared_ptr<NcursesTexture> texture =
    std::dynamic_pointer_cast<NcursesTexture>(props.texture);
    std::string ascii = texture->getAscii();

    int pos_x = static_cast<int>(props.position.x + 1.0f);
    int pos_y = static_cast<int>(props.position.y + 2.0f);
    mvwprintw(_window, pos_y, pos_x, "%c", ascii[props.origin.x]);
}

void NcursesWindow::render(const TextProps &props)
{
    std::string text = props.content;
    int start_y = 0;
    int start_x = 0;

    switch (props.align) {
        case TextAlign::LEFT:
            break;
        case TextAlign::CENTER:
            start_x = (_ncursesbasicwindow.x - props.content.length()) / 2 + 30;
            break;
        case TextAlign::RIGHT:
            start_x = _ncursesbasicwindow.x - props.content.length() + 1 + 30;
            break;
    }
    switch (props.verticalAlign) {
        case TextVerticalAlign::TOP:
            break;
        case TextVerticalAlign::MIDDLE:
            start_y = _ncursesbasicwindow.y / 2;
            break;
        case TextVerticalAlign::BOTTOM:
            start_y = _ncursesbasicwindow.y;
            break;
    }
    mvwprintw(_window, start_y + props.position.y + NCURSES_ORIGIN_OFFSET_Y,
    start_x + props.position.x + NCURSES_ORIGIN_OFFSET_X, "%s", text.c_str());
}

void NcursesWindow::clear()
{
    wrefresh(_window);
    werase(_window);
}

void NcursesWindow::display()
{
    usleep(100000 / 60);
    renderTitle();
}

void NcursesWindow::close()
{
    endwin();
    _running = false;
}

bool NcursesWindow::isOpen(void) const
{
    return _running;
}

events::IKeyEvent::KeyType NcursesWindow::mapNcursesKeyToKeyType(int key)
{
    switch (key)
    {
        case KEY_BACKSPACE:
        case KEY_DC:
        case KEY_ENTER:
        case KEY_HOME:
        case KEY_END:
        case KEY_IC:
        case KEY_NPAGE:
        case KEY_PPAGE:
        case KEY_RESIZE:
        case KEY_LL:
            return events::IKeyEvent::CONTROL;

        case KEY_UP:
        case KEY_DOWN:
        case KEY_LEFT:
        case KEY_RIGHT:
            return events::IKeyEvent::ARROW;

        case KEY_F(1):
        case KEY_F(2):
        case KEY_F(3):
        case KEY_F(4):
        case KEY_F(5):
        case KEY_F(6):
        case KEY_F(7):
        case KEY_F(8):
        case KEY_F(9):
        case KEY_F(10):
        case KEY_F(11):
        case KEY_F(12):
            return events::IKeyEvent::FUNC;


        default:
            if (std::isalpha(key))
                return events::IKeyEvent::CHAR;
            else
                return events::IKeyEvent::UNKNOWN;
    }
}

events::IKeyEvent::KeyCode NcursesWindow::mapNcursesKeyToKeyCode(int key,
    events::IKeyEvent::KeyType type)
{
    if (type == events::IKeyEvent::CONTROL) {
        switch (key) {
            case KEY_BACKSPACE:
                return {.control = events::IKeyEvent::ControlCode::CTRL};
            case KEY_DC:
                return {.control = events::IKeyEvent::ControlCode::ALT};
            case KEY_ENTER:
                return {.control = events::IKeyEvent::ControlCode::SHIFT};
        }
    }
    if (type == events::IKeyEvent::ARROW) {
        switch (key) {
            case KEY_UP:
                return {.arrow = events::IKeyEvent::ArrowCode::UP};
            case KEY_DOWN:
                return {.arrow = events::IKeyEvent::ArrowCode::DOWN};
            case KEY_RIGHT:
                return {.arrow = events::IKeyEvent::ArrowCode::RIGHT};
            case KEY_LEFT:
                return {.arrow = events::IKeyEvent::ArrowCode::LEFT};
        }
    }
    if (type == events::IKeyEvent::CHAR) {
        return {.character = static_cast<char>(key)};
    }
    if (type == events::IKeyEvent::FUNC) {
        return {.func = static_cast<unsigned char>(key - KEY_F(1) + 1)};
    }
    return {.character = static_cast<char>(0)};
}

std::vector<events::EventPtr> NcursesWindow::getEvents()
{
    std::vector<shared::graphics::events::EventPtr> eventsList;

    shared::graphics::events::IKeyEvent::KeyType KeyFindType;
    int event;

    while ((event = getch()) != ERR) {
        KeyFindType = mapNcursesKeyToKeyType(event);

        if (KeyFindType != events::IKeyEvent::UNKNOWN) {
            eventsList.push_back(std::make_shared<events::KeyPressedEvent>
            (KeyFindType, mapNcursesKeyToKeyCode(event, KeyFindType)));
        }
    }

    return eventsList;
}

void NcursesWindow::renderTitle() const
{
        int titleLength = _title.length();

        if (titleLength >= _ncursesbasicwindow.x) {
            mvwprintw(_window, 0, 0, "Error: Title too long");
            return;
        }

        int titleX = (_ncursesbasicwindow.x - titleLength) / 2;
        wattron(_window, A_BOLD | COLOR_PAIR(1));
        mvwprintw(_window, 0, titleX + NCURSES_ORIGIN_OFFSET_X, "%s", _title.c_str());
        wattroff(_window, A_BOLD | COLOR_PAIR(1));
        int padding = 2;
        int barWidth = _ncursesbasicwindow.x;
        int barX = 0;
        int barY = 1;
        wattron(_window, A_ALTCHARSET);
        mvwhline(_window, 1, barX, ACS_HLINE, _ncursesbasicwindow.x + 2);
        for (int index = 0; index < _ncursesbasicwindow.y + NCURSES_ORIGIN_OFFSET_Y; index++) {
            mvwhline(_window, index, 0, ACS_VLINE, 1);
        }
        for (int index = 0; index < _ncursesbasicwindow.y + NCURSES_ORIGIN_OFFSET_Y; index++) {
            mvwhline(_window, index, _ncursesbasicwindow.x +
                NCURSES_ORIGIN_OFFSET_X, ACS_VLINE, 1);
        }
        mvwhline(_window, _ncursesbasicwindow.y + NCURSES_ORIGIN_OFFSET_Y ,
            0, ACS_HLINE, _ncursesbasicwindow.x + 2);
        wattroff(_window, A_ALTCHARSET);
}
