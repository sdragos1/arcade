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
    std::shared_ptr<NcursesTexture> texture = std::dynamic_pointer_cast<NcursesTexture>(props.texture);
    std::string ascii = texture->getAscii();
    Vector2u size = props.size;
    Vector2i position = props.position;
    mvwprintw(_window, position.y + NCURSES_ORIGIN_OFFSET, position.x, "%s", ascii.c_str());
}

void NcursesWindow::render(const TextProps &props)
{
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

std::vector<shared::graphics::events::EventPtr> NcursesWindow::getEvents()
{
    std::vector<shared::graphics::events::EventPtr> eventsList;

    int ch;
    while ((ch = getch()) != ERR) {
        shared::graphics::events::IKeyEvent::KeyType keyType = NcursesEvents::mapNcursesKeyToKeyType(ch);
        if (keyType != shared::graphics::events::IKeyEvent::UNKNOWN) {
            eventsList.push_back(std::make_shared<shared::graphics::events::KeyPressedEvent>(
                keyType, NcursesEvents::mapNcursesKeyToKeyCode(ch, keyType)));
        }
    }

    return eventsList;
}

void NcursesWindow::renderTitle() const
{
        int titleLength = _title.length();
        int windowWidth = getmaxx(_window);

        // Ensure title doesn't exceed window width
        if (titleLength >= windowWidth) {
            mvwprintw(_window, 0, 0, "Error: Title too long");
            return;
        }

        // Calculate position for centering the title
        int titleX = (windowWidth - titleLength) / 2;

        // Apply bold and color attributes to the title
        wattron(_window, A_BOLD | COLOR_PAIR(1)); // Adjust color pair as needed
        mvwprintw(_window, 0, titleX, "%s", _title.c_str());
        wattroff(_window, A_BOLD | COLOR_PAIR(1));

        // Add padding around the title
        int padding = 2;
        for (int i = 0; i < padding; ++i) {
            mvwprintw(_window, 0, titleX - i - 1, " "); // Left padding
            mvwprintw(_window, 0, titleX + titleLength + i, " "); // Right padding
        }

        // Draw a bar below the title spanning the width of the window
        int barWidth = windowWidth;
        int barX = 0;
        int barY = 1; // Adjust the position of the bar as needed
        wattron(_window, A_ALTCHARSET); // Enable drawing special characters
        mvwhline(_window, barY, barX, ACS_HLINE, barWidth);
        wattroff(_window, A_ALTCHARSET); // Disable drawing special characters
}
