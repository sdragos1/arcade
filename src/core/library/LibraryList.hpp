/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** LibraryList
*/

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "loader/DLLoader.hpp"
#include "../common/games/IGame.hpp"
#include "../common/types/Libraries.hpp"
#include "../common/graphics/IGraphicsProvider.hpp"

template <typename T>
class LibraryList
{
    public:

        LibraryList(shared::types::LibraryType type, std::vector<std::string> allLibrariesPath)
        {
            _libraryType = type;
            _index = 0;

            for (const auto& path : allLibrariesPath) {
                std::shared_ptr<DLLoader<std::shared_ptr<T>>> loaders = std::make_shared<DLLoader<std::shared_ptr<T>>>(path);
                if (loaders->getType(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)) == type) {
                    _libraryList.push_back(loaders->getInstance(SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_LOADER_NAME)));
                    _libraryLoader.push_back(loaders);
                }
            }
        }

        ~LibraryList()
        {
            for (int index = 0; index < _libraryLoader.size(); index++) {
                _libraryList[index].reset();
            }
        }

        shared::types::LibraryType getLibraryType() const
        {
            return _libraryType;
        }

        std::size_t getIndex() const
        {
            return _index;
        }

        void incrementeIndex()
        {
            if (_index + 1 == _libraryLoader.size()) {
                _index = 0;
            } else {
                _index++;
            }
        }

        void decrementeIndex()
        {
            if (_index - 1 == -1) {
                _index = _libraryLoader.size() - 1;
            } else {
                _index--;
            }
        }

        std::shared_ptr<T> getCurrentLibrary()
        {
            return _libraryList[_index];
        }

    protected:
        shared::types::LibraryType                                      _libraryType;
        std::vector<std::shared_ptr<T>>                                 _libraryList;
        std::vector<std::shared_ptr<DLLoader<std::shared_ptr<T>>>>      _libraryLoader;
        std::size_t                                                     _index;
};