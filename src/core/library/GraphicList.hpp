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
        explicit GraphicList(std::vector<std::string> allLibrariesPath);

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
        void incrementeIndex();

        /**
         * @brief Decremente index of Library
         */
        void decrementeIndex();

        /**
         * @brief Get the Current Library object
         * @return std::shared_ptr<shared::graphics::IGraphicsProvider> Current Library
         */
        std::shared_ptr<shared::graphics::IGraphicsProvider> getCurrentLibrary();

    protected:
        std::vector<std::shared_ptr<shared::graphics::IGraphicsProvider>>   _libraryList;
        std::vector<std::shared_ptr<DLLoader<std::shared_ptr<shared::graphics::IGraphicsProvider>>>>
        _libraryLoader;
        std::size_t     _index;
};
