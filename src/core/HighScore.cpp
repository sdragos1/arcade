/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** highscoreHandlers
*/

#include <fstream>
#include <iostream>
#include <iostream>
#include "Core.hpp"

std::size_t Core::_scoreIntoInt(std::string score)
{
    std::stringstream stream(score);
    std::size_t scoreInt;

    stream >> scoreInt;
    return scoreInt;
}

std::vector<std::string> Core::_fileIntoVector()
{
    std::fstream highscoreFile("assets/highscore.txt",
    std::ios::in | std::ios::out | std::ios::app);
    std::vector<std::string> lignes;
    std::string ligne;
    while (getline(highscoreFile, ligne)) {
        lignes.push_back(ligne);
    }
    return lignes;
}

void Core::_highscoreHandlers()
{
    int actualScore = _currGame->getScore();
    std::string actualGames = _currGame->getManifest().name;
    std::vector<std::string> fileLines = _fileIntoVector();
    bool gameFound = false;

    for (int index = 0; index < fileLines.size(); index++) {
        std::string segment;
        std::istringstream streamLine(fileLines[index]);
        std::vector<std::string> seglist;

        while (std::getline(streamLine, segment, '|')) {
            seglist.push_back(segment);
        }

        if (actualGames == seglist[1]) {
            if (actualScore > _scoreIntoInt(seglist[2]))
                fileLines[index] = _playerName + "|" + actualGames + "|" +
                std::to_string(actualScore);
            gameFound = true;
        }
    }
    if (gameFound) {
        std::ofstream deleteFile("assets/highscore.txt",
        std::ios::out | std::ios::trunc);

        if (deleteFile.is_open()) {
            deleteFile << "";
            deleteFile.close();
        }

        std::fstream highscoreFile("assets/highscore.txt",
        std::ios::in | std::ios::out | std::ios::app);
        for (int index = 0; index < fileLines.size(); index++) {
            highscoreFile << fileLines[index] << std::endl;
        }
    } else {
        std::fstream highscoreFile("assets/highscore.txt",
        std::ios::in | std::ios::out | std::ios::app);
        std::string lineHighscore = _playerName + "|" +
        actualGames + "|" + std::to_string(actualScore);
        highscoreFile << lineHighscore << std::endl;
    }
}
