/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** GamesList
*/

#include "GameList.hpp"

GameList::GameList(std::vector<std::string> allLibrariesPath)
{
    _index = 0;

    for (const auto& path : allLibrariesPath) {
        std::shared_ptr<DLLoader<shared::games::IGameProvider *>> loaders =
        std::make_shared<DLLoader<shared::games::IGameProvider *>>(path);
        if (loaders->getType(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME))
        == shared::types::LibraryType::GAME) {
            shared::games::IGameProvider *instance =
            loaders->getInstance(SHARED_STRINGIFY(SHARED_GAME_PROVIDER_GETTER_NAME));
            _libraryList.push_back(instance->createInstance());
            _libraryLoader.push_back(loaders);
            delete instance;
        }
    }
}

GameList::~GameList()
{
    for (int index = 0; index < _libraryList.size(); index++) {
        _libraryList[index].reset();
    }
}

std::size_t GameList::getNbGame() const
{
    return _libraryList.size();
}

void GameList::incrementIndex()
{
    if (_index + 1 == _libraryList.size()) {
        _index = 0;
    } else {
        _index++;
    }
}

void GameList::decrementIndex()
{
    if (_index - 1 == -1) {
        _index = _libraryList.size() - 1;
    } else {
        _index--;
    }
}

std::shared_ptr<shared::games::IGame> GameList::getCurrentGame()
{
    return _libraryList[_index];
}
