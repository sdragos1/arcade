/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include <iostream>
#include "Core.hpp"

void Core::runMenu()
{
    std::size_t indexGraphic = _librariesRenderer->getIndex();
    std::size_t indexGame = _librariesGame->getIndex();
    _launchGame = false;

    if (_currRenderer == nullptr)
        _currRenderer = _librariesRenderer->getCurrentLibrary();
    _currWindow = _currRenderer->createWindow({
        .size = (Vector2u) {1920, 1080},
        .mode = IWindow::WindowMode::WINDOWED,
        .fps = 120,
        .title = "Menu",
        .icon = "none"});

    std::vector<shared::graphics::TextProps> listNameGame = _TextPropsListGame(indexGame);
    shared::graphics::TextProps titleGame = _TextPropsTitleGame();

    std::vector<shared::graphics::TextProps> listNameGraphic = _TextPropsListGraphic(indexGraphic);
    shared::graphics::TextProps titleGraphic = _TextPropsTitleGraphic();

    shared::graphics::TextProps name = _TextPropsName();
    shared::graphics::TextProps titleName = _TextPropsTitleName();

    while (_currWindow->isOpen()) {
        _eventsMenu(indexGraphic, indexGame, name, listNameGame, listNameGraphic);
        if (_currWindow->isOpen() == false)
            continue;
        _currWindow->clear();
        _displaylib(indexGraphic, listNameGraphic, titleGraphic);
        _displaylib(indexGame, listNameGame, titleGame);
        _currWindow->render(titleName);
        if (!name.content.empty())
            _currWindow->render(name);
        _currWindow->display();
    }

    for (int index = 0; index < _librariesGame->getLibraryList().size(); index++) {
        listNameGame[index].font.reset();
    }
    titleGame.font.reset();

    for (int index = 0; index < _librariesRenderer->getLibraryList().size(); index++) {
        listNameGraphic[index].font.reset();
    }
    titleGraphic.font.reset();

    name.font.reset();
    titleName.font.reset();

    _librariesRenderer->setIndex(indexGraphic);
    _librariesGame->setIndex(indexGame);
    _currLibIndex = _librariesRenderer->getIndex();
    _currWindow.release();
}


shared::graphics::TextProps Core::_TextPropsTitleGame()
{
    int posBeginY = 7 + static_cast<int>(_librariesRenderer->getLibraryList().size());
    shared::graphics::TextProps choiceGame {
        .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
        .fontSize = 20,
        .content = "Choix du jeux a lancer:",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {255, 255, 255, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2i) {5, posBeginY}
    };
    return choiceGame;
}


std::vector<shared::graphics::TextProps> Core::_TextPropsListGame(std::size_t indexGame)
{
    std::vector<shared::graphics::TextProps> list;
    std::vector<std::shared_ptr<shared::games::IGame>> libraryList = _librariesGame->getLibraryList();
    int posBeginY = 7 + static_cast<int>(_librariesRenderer->getLibraryList().size());
    std::string star = "";

    for (std::size_t index = 0; index < libraryList.size(); index++) {
        if (index == indexGame)
            star = "   *";
        else
            star = "";
        shared::graphics::TextProps nameGame {
            .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
            .fontSize = 20,
            .content = libraryList[index]->getManifest().name + star,
            .align = shared::graphics::LEFT,
            .verticalAlign = shared::graphics::TOP,
            .color = shared::types::Color {255, 255, 255, 255},
            .size = (shared::types::Vector2u) {5, 5},
            .position = (shared::types::Vector2i) {7, posBeginY + static_cast<int>(index) + 1}
        };
        list.push_back(nameGame);
    }
    return list;
}

shared::graphics::TextProps Core::_TextPropsTitleGraphic()
{
    shared::graphics::TextProps choiceGraphic {
        .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
        .fontSize = 20,
        .content = "Choix de la bibliotheque graphique:",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {255, 255, 255, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2i) {5, 5}
    };
    return choiceGraphic;
}


std::vector<shared::graphics::TextProps> Core::_TextPropsListGraphic(std::size_t indexGraphic)
{
    std::vector<shared::graphics::TextProps> list;
    std::vector<shared::graphics::IGraphicsProvider *> libraryList = _librariesRenderer->getLibraryList();
    std::string star = "";

    for (std::size_t index = 0; index < libraryList.size(); index++) {
        if (index == indexGraphic)
            star = "   *";
        else
            star = "";
        shared::graphics::TextProps nameGraphic {
            .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
            .fontSize = 20,
            .content = libraryList[index]->getManifest().name + star,
            .align = shared::graphics::LEFT,
            .verticalAlign = shared::graphics::TOP,
            .color = shared::types::Color {255, 255, 255, 255},
            .size = (shared::types::Vector2u) {5, 5},
            .position = (shared::types::Vector2i) {7, 6 + static_cast<int>(index)}
        };
        list.push_back(nameGraphic);
    }
    return list;
}

shared::graphics::TextProps Core::_TextPropsTitleName()
{
    int posBeginY = 9 + static_cast<int>(_librariesRenderer->getLibraryList().size()) + static_cast<int>(_librariesGame->getLibraryList().size());

    shared::graphics::TextProps choiceName {
        .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
        .fontSize = 20,
        .content = "Nom du joueur:",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {255, 255, 255, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2i) {5, posBeginY}
    };
    return choiceName;
}

shared::graphics::TextProps Core::_TextPropsName()
{
    int posBeginY = 9 + static_cast<int>(_librariesRenderer->getLibraryList().size()) + static_cast<int>(_librariesGame->getLibraryList().size());

    shared::graphics::TextProps name {
        .font = nullptr,
        .fontSize = 20,
        .content = "",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {255, 255, 255, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2i) {7, posBeginY + 1}
    };
    return name;
}

void Core::_displaylib(std::size_t indexlib,
std::vector<shared::graphics::TextProps> listNamelib, shared::graphics::TextProps titlelib)
{
    _currWindow->render(titlelib);
    for (std::size_t index = 0; index < listNamelib.size(); index++) {
        _currWindow->render(listNamelib[index]);
    }
}

void Core::_eventsMenu(std::size_t &indexGraphic, std::size_t &indexGame, shared::graphics::TextProps &name,
std::vector<shared::graphics::TextProps> &listNameGame, std::vector<shared::graphics::TextProps> &listNameGraphic)
{
    std::vector<std::shared_ptr<shared::graphics::events::IEvent>> events = _currWindow->getEvents();

    for (int index = 0; index < events.size(); index++) {
        if (events[index]->getType() == shared::graphics::events::WINDOW_CLOSE) {
            _currWindow->close();
        }
        if (events[index]->getType() == shared::graphics::events::KEY_PRESS) {
            auto EventKey = std::dynamic_pointer_cast<shared::graphics::events::IKeyEvent>(events[index]);
            
            if (EventKey != nullptr) {
                if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::ARROW) {
                    if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::DOWN) {
                        listNameGraphic[indexGraphic].content.erase(listNameGraphic[indexGraphic].content.size() - 4);
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGraphic + 1 == _librariesRenderer->getNbGraphic())
                            indexGraphic = 0;
                        else
                            indexGraphic += 1;
                        listNameGraphic[indexGraphic].content += "   *";
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::UP) {
                        listNameGraphic[indexGraphic].content.erase(listNameGraphic[indexGraphic].content.size() - 4);
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGraphic - 1 == -1)
                            indexGraphic = _librariesRenderer->getNbGraphic() - 1;
                        else
                            indexGraphic -= 1;
                        listNameGraphic[indexGraphic].content += "   *";
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::LEFT) {
                        listNameGame[indexGame].content.erase(listNameGame[indexGame].content.size() - 4);
                        listNameGame[indexGame].font.reset();
                        listNameGame[indexGame].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGame - 1 == -1)
                            indexGame = _librariesGame->getNbGame() - 1;
                        else
                            indexGame -= 1;
                        listNameGame[indexGame].content += "   *";
                        listNameGame[indexGame].font.reset();
                        listNameGame[indexGame].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::RIGHT) {
                        listNameGame[indexGame].content.erase(listNameGame[indexGame].content.size() - 4);
                        listNameGame[indexGame].font.reset();
                        listNameGame[indexGame].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGame + 1 == _librariesGame->getNbGame())
                            indexGame = 0;
                        else
                            indexGame += 1;
                        listNameGame[indexGame].content += "   *";
                        listNameGame[indexGame].font.reset();
                        listNameGame[indexGame].font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                }
                if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::CHAR) {
                    if ('a' <= EventKey->getKeyCode().character && EventKey->getKeyCode().character <= 'z')
                        name.content += EventKey->getKeyCode().character;
                        name.font.reset();
                        name.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                }
                if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::FUNC) {
                    if (EventKey->getKeyCode().func == F1) {
                        if (!name.content.empty())
                            name.content.erase(name.content.size() - 1);
                        if (name.font)
                            name.font.reset();
                        name.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().func == F2) {
                        _currWindow->close();
                        _launchGame = false;
                    }
                    if (EventKey->getKeyCode().func == F3) {
                        _currWindow->close();
                        _launchGame = true;
                    }
                }
            }
        }
    }
}
