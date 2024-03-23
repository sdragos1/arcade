/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** LibraryList
*/

#include "GraphicList.hpp"

GraphicList::GraphicList(std::vector<std::string> allLibrariesPath)
{
    _index = 0;

    for (const auto& path : allLibrariesPath) {
        std::shared_ptr<DLLoader<std::shared_ptr<shared::graphics::IGraphicsProvider>>> loaders =
        std::make_shared<DLLoader<std::shared_ptr<shared::graphics::IGraphicsProvider>>>(path);
        if (loaders->getType(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)) ==
        shared::types::LibraryType::GRAPHIC) {
            std::shared_ptr<shared::graphics::IGraphicsProvider> instance =
            loaders->getInstance(SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_LOADER_NAME));
            _libraryList.push_back(instance);
            _libraryLoader.push_back(loaders);
        }
    }
}

GraphicList::~GraphicList()
{
    for (int index = 0; index < _libraryList.size(); index++) {
        _libraryList[index].reset();
    }
}

std::size_t GraphicList::getNbGraphic() const
{
    return _libraryList.size();
}

void GraphicList::incrementeIndex()
{
    if (_index + 1 == _libraryList.size()) {
        _index = 0;
    } else {
        _index++;
    }
}

void GraphicList::decrementeIndex()
{
    if (_index - 1 == -1) {
        _index = _libraryList.size() - 1;
    } else {
        _index--;
    }
}

std::shared_ptr<shared::graphics::IGraphicsProvider> GraphicList::getCurrentLibrary()
{
    return _libraryList[_index];
}
