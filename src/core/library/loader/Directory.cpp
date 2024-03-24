/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Directory
*/

#include "Directory.hpp"

Directory::Directory(const std::string &libraryPath)
{
    _libPath = libraryPath;
    if (!std::filesystem::is_directory(libraryPath)) {
        throw std::runtime_error("Can't open directory: " + libraryPath);
    }
}

Directory::~Directory()
{
}

std::vector<std::string> Directory::getListLibraries()
{
    std::vector<std::string> librariesPath;

    for (const auto &entry : std::filesystem::directory_iterator(_libPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            librariesPath.push_back(entry.path().string());
        }
    }
    return librariesPath;
}
