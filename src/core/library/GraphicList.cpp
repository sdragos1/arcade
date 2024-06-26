/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** LibraryList
*/

#include "GraphicList.hpp"

GraphicList::GraphicList(std::vector<std::string> allLibrariesPath, std::string defaultLib)
{
    int nbLibGraphic = 0;
    _index = -1;

    for (int index = 0; index <  allLibrariesPath.size(); index++) {
        std::shared_ptr<DLLoader<shared::graphics::IGraphicsProvider *>> loaders =
        std::make_shared<DLLoader<shared::graphics::IGraphicsProvider *>>
        (allLibrariesPath[index]);
        if (loaders->getType(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)) ==
        shared::types::LibraryType::GRAPHIC) {
            if (allLibrariesPath[index] == defaultLib)
                _index = nbLibGraphic;
            shared::graphics::IGraphicsProvider *instance =
            loaders->getInstance(SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_GETTER_NAME));
            _libraryList.push_back(instance);
            _libraryLoader.push_back(loaders);
            nbLibGraphic++;
        }
    }
    if (_index == -1) {
        throw std::logic_error("Default Graphic Library doesn't exist: " + defaultLib);
    }
}

GraphicList::~GraphicList()
{
    for (int index = 0; index < _libraryList.size(); index++) {
        delete _libraryList[index];
    }
}

std::size_t GraphicList::getNbGraphic() const
{
    return _libraryList.size();
}

void GraphicList::incrementIndex()
{
    if (_index + 1 == _libraryList.size()) {
        _index = 0;
    } else {
        _index++;
    }
}

void GraphicList::decrementIndex()
{
    if (_index - 1 == -1) {
        _index = _libraryList.size() - 1;
    } else {
        _index--;
    }
}

shared::graphics::IGraphicsProvider* GraphicList::getCurrentLibrary()
{
    return _libraryList[_index];
}

std::size_t GraphicList::getIndex() const noexcept
{
    return _index;
}

std::vector<shared::graphics::IGraphicsProvider *> GraphicList::getLibraryList()
{
    return _libraryList;
}

void GraphicList::setIndex(std::size_t newIndex)
{
    if (newIndex >= _libraryList.size())
        return;
    _index = newIndex;
}
