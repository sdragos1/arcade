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
#include "../common/types/Libraries.hpp"

template <typename T>
class DLLoader
{
    public:
        explicit DLLoader(const std::string libraryPath) : _libraryInstance(nullptr)
        {
            _libraryPath = libraryPath;
            _libraryInstance = dlopen(libraryPath.c_str(), RTLD_LAZY);
            if (!_libraryInstance) {
                throw std::runtime_error(dlerror());
            }
        }

        ~DLLoader()
        {
            dlclose(_libraryInstance);
        }

        shared::types::LibraryType getType(const std::string functionName)
        {
            shared::types::LibraryType (*createInstance)();

            createInstance =
            (shared::types::LibraryType (*)()) dlsym(_libraryInstance, functionName.c_str());
            if (createInstance == nullptr) {
                throw std::runtime_error(dlerror());
            }
            return createInstance();
        }

        T getInstance(const std::string functionName)
        {
            T (*createInstance)();

            createInstance = (T (*)()) dlsym(_libraryInstance, functionName.c_str());
            if (!createInstance) {
                throw std::runtime_error(dlerror());
            }
            return createInstance();
        }

    protected:
        std::string _libraryPath;
        void *_libraryInstance;
};
