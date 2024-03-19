/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#pragma once

#include <string>
#include <memory>
#include <dlfcn.h>
#include <cstring>

template <typename T>
class DLLoader
{
    public:

        /**
         * @brief Construct a new DLLoader object
         * @param libraryPath Path of the Library to open
         */
        DLLoader(const std::string libraryPath);

        /**
         * @brief Destroy the DLLoader object
         */
        ~DLLoader();

        /**
         * @brief Get the Instance object
         * @param functionName The entrypoint name's of library
         * @return T* 
         */
        T *getInstance(const std::string functionName);

    protected:
        void *_libraryInstance;
};
