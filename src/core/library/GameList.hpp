/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** GamesList
*/

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "loader/DLLoader.hpp"
#include "../../common/games/IGame.hpp"
#include "../../common/types/Libraries.hpp"

class GameList
{
    public:
        /**
         * @brief Construct a new Graphic List object
         * @param allLibrariesPath All Libraries path
         */
        explicit GameList(std::vector<std::string> allLibrariesPath);

        /**
         * @brief Destroy the Game List object
         */
        ~GameList();

        /**
         * @brief Get the Nb Game object
         * @return std::size_t Number of Game Library
         */
        std::size_t getNbGame() const;


        /**
         * @brief Incremente index of Library
         */
        void incrementeIndex();

        /**
         * @brief Decremente index of Library
         */
        void decrementeIndex();

        /**
         * @brief Get the Current Game object
         * @return std::shared_ptr<shared::games::IGame> Current Game Library
         */
        std::shared_ptr<shared::games::IGame> getCurrentGame();

    protected:
        std::vector<std::shared_ptr<shared::games::IGame>> _libraryList;
        std::vector<std::shared_ptr<DLLoader<std::shared_ptr<shared::games::IGameProvider>>>>
        _libraryLoader;
        std::size_t _index;
};
