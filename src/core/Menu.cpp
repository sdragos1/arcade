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
        .size = (Vector2u) {48, 27},
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

    shared::graphics::TextProps highscore = _TextPropsHighscore(13.0 +
    static_cast<float>(_librariesRenderer->getLibraryList().size()) +
    static_cast<float>(_librariesGame->getLibraryList().size()));
    shared::graphics::TextProps titleHighscore = _TextPropsHighscore(12.0 +
    static_cast<float>(_librariesRenderer->getLibraryList().size()) +
    static_cast<float>(_librariesGame->getLibraryList().size()));

    shared::graphics::TextureProps background = _TextPropsBackGround();
    shared::graphics::TextureProps frame = _TextPropsFrame(2.0);

    while (_currWindow->isOpen()) {
        _eventsMenu(indexGraphic, indexGame, name, listNameGame, listNameGraphic);
        if (_currWindow->isOpen() == false)
            continue;
        _currWindow->clear();
        _currWindow->render(background);
        _currWindow->render(frame);
        _displaylib(indexGraphic, listNameGraphic, titleGraphic);
        _displaylib(indexGame, listNameGame, titleGame);
        _currWindow->render(titleName);
        if (!_playerName.empty())
            _currWindow->render(name);
        _setHighscore(highscore, indexGame, titleHighscore, listNameGame);
        _currWindow->render(titleHighscore);
        _currWindow->render(highscore);
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

shared::graphics::TextureProps Core::_TextPropsFrame(float PosX)
{
    shared::graphics::TextureProps background {
        .texture = _librariesRenderer->getCurrentLibrary()->createTexture("assets/menu/case.png",
        "assets/menu/case.txt"),
        .binTileSize = (shared::types::Vector2f) {40, 40},
        .origin = (shared::types::Vector2u) {0, 0},
        .size = (shared::types::Vector2u) {19, 18},
        .position = (shared::types::Vector2f) {PosX, 3.0}
    };
    return background;
}

shared::graphics::TextureProps Core::_TextPropsBackGround()
{
    shared::graphics::TextureProps background {
        .texture = _librariesRenderer->getCurrentLibrary()->createTexture(
            "assets/menu/background.jpg", "assets/menu/background.txt"),
        .binTileSize = (shared::types::Vector2f) {40, 40},
        .origin = (shared::types::Vector2u) {0, 0},
        .size = (shared::types::Vector2u) {48, 27},
        .position = (shared::types::Vector2f) {0.0, 0.0}
    };
    return background;
}


shared::graphics::TextProps Core::_TextPropsTitleGame()
{
    float posBeginY = 7 + static_cast<int>(_librariesRenderer->getLibraryList().size());
    shared::graphics::TextProps choiceGame {
        .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
        .fontSize = 20,
        .content = "Choix du jeux a lancer:",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {0, 0, 0, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2f) {5.0, posBeginY}
    };
    return choiceGame;
}

std::vector<shared::graphics::TextProps> Core::_TextPropsListGame(std::size_t indexGame)
{
    std::vector<shared::graphics::TextProps> list;
    std::vector<std::shared_ptr<shared::games::IGame>> libraryList =
    _librariesGame->getLibraryList();
    float posBeginY = 7.0 + static_cast<float>(_librariesRenderer->getLibraryList().size());
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
            .color = shared::types::Color {0, 0, 0, 255},
            .size = (shared::types::Vector2u) {5, 5},
            .position = (shared::types::Vector2f) {7.0, posBeginY + static_cast<int>(index) + 1}
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
        .color = shared::types::Color {0, 0, 0, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2f) {5.0, 5.0}
    };
    return choiceGraphic;
}


std::vector<shared::graphics::TextProps>
    Core::_TextPropsListGraphic(std::size_t indexGraphic)
{
    std::vector<shared::graphics::TextProps> list;
    std::vector<shared::graphics::IGraphicsProvider *> libraryList =
        _librariesRenderer->getLibraryList();
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
            .color = shared::types::Color {0, 0, 0, 255},
            .size = (shared::types::Vector2u) {5, 5},
            .position = (shared::types::Vector2f) {7.0, 6 + static_cast<float>(index)}
        };
        list.push_back(nameGraphic);
    }
    return list;
}

shared::graphics::TextProps Core::_TextPropsTitleName()
{
    float posBeginY = 9.0 + static_cast<float>(_librariesRenderer->getLibraryList().size()) +
    static_cast<int>(_librariesGame->getLibraryList().size());

    shared::graphics::TextProps choiceName {
        .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
        .fontSize = 20,
        .content = "Nom du joueur:",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {0, 0, 0, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2f) {5.0, posBeginY}
    };
    return choiceName;
}

shared::graphics::TextProps Core::_TextPropsName()
{
    float posBeginY = 9.0 + static_cast<float>(_librariesRenderer->getLibraryList().size()) +
    static_cast<float>(_librariesGame->getLibraryList().size());

    shared::graphics::TextProps name {
        .font = nullptr,
        .fontSize = 20,
        .content = _playerName,
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {0, 0, 0, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2f) {7.0, posBeginY + 1}
    };
    if (!_playerName.empty())
        name.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
    return name;
}

shared::graphics::TextProps Core::_TextPropsHighscore(float posBeginY)
{
    shared::graphics::TextProps choiceName {
        .font = _currRenderer->createFont("assets/fonts/Crang.ttf"),
        .fontSize = 20,
        .content = "",
        .align = shared::graphics::LEFT,
        .verticalAlign = shared::graphics::TOP,
        .color = shared::types::Color {0, 0, 0, 255},
        .size = (shared::types::Vector2u) {5, 5},
        .position = (shared::types::Vector2f) {5.0, posBeginY}
    };
    return choiceName;
}

void Core::_setHighscore(shared::graphics::TextProps &highscore, std::size_t &indexGame,
shared::graphics::TextProps &titleHighscore, std::vector<shared::graphics::TextProps> &listNameGame)
{
    std::vector<std::shared_ptr<shared::games::IGame>> libraryList =
    _librariesGame->getLibraryList();
    std::vector<std::string> fileLines = _fileIntoVector();

    for (int index = 0; index < fileLines.size(); index++) {
        std::string segment;
        std::istringstream streamLine(fileLines[index]);
        std::vector<std::string> seglist;

        while (std::getline(streamLine, segment, '|')) {
            seglist.push_back(segment);
        }

        if (libraryList[indexGame]->getManifest().name == seglist[1]) {
            titleHighscore.content = "Meilleur score pour:     " + seglist[1];
            titleHighscore.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
            highscore.content = seglist[0] + " a un score de " + seglist[2];
            highscore.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
        }
    }
}

void Core::_displaylib(std::size_t indexlib,
std::vector<shared::graphics::TextProps> listNamelib, shared::graphics::TextProps titlelib)
{
    _currWindow->render(titlelib);
    for (std::size_t index = 0; index < listNamelib.size(); index++) {
        _currWindow->render(listNamelib[index]);
    }
}

void Core::_eventsMenu(std::size_t &indexGraphic, std::size_t &indexGame,
    shared::graphics::TextProps &name,
    std::vector<shared::graphics::TextProps> &listNameGame,
    std::vector<shared::graphics::TextProps> &listNameGraphic)
{
    std::vector<std::shared_ptr<shared::graphics::events::IEvent>> events =
        _currWindow->getEvents();

    for (int index = 0; index < events.size(); index++) {
        if (events[index]->getType() == shared::graphics::events::WINDOW_CLOSE) {
            _currWindow->close();
        }
        if (events[index]->getType() == shared::graphics::events::KEY_PRESS) {
            auto EventKey =
                std::dynamic_pointer_cast<shared::graphics::events::IKeyEvent>(events[index]);
            if (EventKey != nullptr) {
                if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::ARROW) {
                    if (EventKey->getKeyCode().arrow ==
                        shared::graphics::events::IKeyEvent::ArrowCode::DOWN) {
                        listNameGraphic[indexGraphic].content.
                            erase(listNameGraphic[indexGraphic].content.size() - 4);
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].font =
                            _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGraphic + 1 == _librariesRenderer->getNbGraphic())
                            indexGraphic = 0;
                        else
                            indexGraphic += 1;
                        listNameGraphic[indexGraphic].content += "   *";
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].font =
                            _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().arrow ==
                        shared::graphics::events::IKeyEvent::ArrowCode::UP) {
                        listNameGraphic[indexGraphic].
                            content.erase(listNameGraphic[indexGraphic].content.size() - 4);
                        listNameGraphic[indexGraphic].
                            font.reset();
                        listNameGraphic[indexGraphic].
                            font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGraphic - 1 == -1)
                            indexGraphic = _librariesRenderer->getNbGraphic() - 1;
                        else
                            indexGraphic -= 1;
                        listNameGraphic[indexGraphic].content += "   *";
                        listNameGraphic[indexGraphic].font.reset();
                        listNameGraphic[indexGraphic].
                            font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().arrow ==
                        shared::graphics::events::IKeyEvent::ArrowCode::LEFT) {
                        listNameGame[indexGame].
                            content.erase(listNameGame[indexGame].content.size() - 4);
                        listNameGame[indexGame].
                            font.reset();
                        listNameGame[indexGame].
                            font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGame - 1 == -1)
                            indexGame = _librariesGame->getNbGame() - 1;
                        else
                            indexGame -= 1;
                        listNameGame[indexGame].content += "   *";
                        listNameGame[indexGame]
                            .font.reset();
                        listNameGame[indexGame].font =
                            _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().arrow ==
                        shared::graphics::events::IKeyEvent::ArrowCode::RIGHT) {
                        listNameGame[indexGame].
                            content.erase(listNameGame[indexGame].content.size() - 4);
                        listNameGame[indexGame].font.reset();
                        listNameGame[indexGame].
                            font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        if (indexGame + 1 == _librariesGame->getNbGame())
                            indexGame = 0;
                        else
                            indexGame += 1;
                        listNameGame[indexGame].content += "   *";
                        listNameGame[indexGame].font.reset();
                        listNameGame[indexGame]
                            .font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                }
                if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::CHAR) {
                    if ('a' <= EventKey->getKeyCode().character &&
                    EventKey->getKeyCode().character <= 'z') {
                        if (_playerName.size() < 34) {
                            _playerName += EventKey->getKeyCode().character;
                            name.content = _playerName;
                            name.font.reset();
                            name.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                        }
                    }
                }
                if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::FUNC) {
                    if (EventKey->getKeyCode().func == F1) {
                        if (!_playerName.empty())
                            _playerName.erase(_playerName.size() - 1);
                        if (name.font)
                            name.font.reset();
                        name.content = _playerName;
                        name.font = _currRenderer->createFont("assets/fonts/Crang.ttf");
                    }
                    if (EventKey->getKeyCode().func == F2) {
                        _currWindow->close();
                        _launchGame = false;
                    }
                    if (EventKey->getKeyCode().func == F3) {
                        if (!_playerName.empty()) {
                            _currWindow->close();
                            _launchGame = true;
                        }
                    }
                }
            }
        }
    }
}
