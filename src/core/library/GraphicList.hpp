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
#include "../../common/types/Libraries.hpp"
#include "../../common/graphics/IGraphicsProvider.hpp"

class GraphicList
{
    public:
        /**
         * @brief Construct a new Graphic List object
         * @param allLibrariesPath All Libraries path
         */
        explicit GraphicList(std::vector<std::string> allLibrariesPath, std::string defaultLib);

        /**
         * @brief Destroy the Graphic List object
         */
        ~GraphicList();

        /**
         * @brief Get the Nb Graphic object
         * @return std::size_t Number of Graphic Library
         */
        std::size_t getNbGraphic() const;

        /**
         * @brief Incremente index of Library
         */
        void incrementIndex();

        /**
         * @brief Decremente index of Library
         */
        void decrementIndex();

        /**
         * @brief Get the Current Library object
         * @return std::shared_ptr<shared::graphics::IGraphicsProvider> Current Library
         */
        shared::graphics::IGraphicsProvider *getCurrentLibrary();

        /**
         * @brief Gets the index of the current lib
         * @return std::size_t Index of Library
         */
        std::size_t getIndex() const noexcept;

    protected:
        std::vector<shared::graphics::IGraphicsProvider *>   _libraryList;
        std::vector<std::shared_ptr<DLLoader<shared::graphics::IGraphicsProvider *>>>
        _libraryLoader;
        std::size_t     _index;
};
