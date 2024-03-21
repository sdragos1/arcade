/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Directory
*/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <cstring>
#include <dirent.h>
#include <iostream>

class Directory
{
    public:

        /**
         * @brief Construct a new Directory object
         * @param directoryPath Path of the directory to open
         */
        Directory(const std::string &directoryPath);

        /**
         * @brief Destroy the Directory object
         */
        ~Directory();

        /**
         * @brief Get the List Libraries object
         * @return std::vector<std::string> 
         */
        std::vector<std::string> getListLibraries();

    private:
        DIR *           _dir;
        struct dirent * _entry; 
        std::string     _libPath;
};

typedef std::unique_ptr<Directory> UniqueDirectory;
