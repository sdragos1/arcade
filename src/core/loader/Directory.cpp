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
    _dir = opendir(libraryPath.c_str());
    if (_dir == NULL) {
        throw std::runtime_error("Can't open directory: " + libraryPath);
    }
}

Directory::~Directory()
{
    if (_dir) {
        closedir(_dir);
    }
}

std::vector<std::string> Directory::getListLibraries()
{
    std::vector<std::string> LibrariesPath;

    _entry = readdir(_dir);
    while (_entry != nullptr) {
        if ((_entry->d_type == DT_REG) && (std::strstr(_entry->d_name, ".so") != nullptr)) {
            LibrariesPath.emplace_back(_libPath + _entry->d_name);
        }
        _entry = readdir(_dir);
    }
    return LibrariesPath;
}
