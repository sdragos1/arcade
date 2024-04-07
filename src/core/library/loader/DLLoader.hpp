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
#include "../../../../common/types/Libraries.hpp"

template <typename T>
class DLLoader
{
    public:
        /**
         * @brief Construct a new DLLoader object
         * @param libraryPath
         */
        explicit DLLoader(const std::string libraryPath) : _libraryInstance(nullptr)
        {
            _libraryPath = libraryPath;
            _libraryInstance = dlopen(libraryPath.c_str(), RTLD_LAZY);
            if (!_libraryInstance) {
                throw std::runtime_error(dlerror());
            }
        }

        /**
         * @brief Destroy the DLLoader object
         */
        ~DLLoader()
        {
            if (dlclose(_libraryInstance) != 0) {
                std::cout << "ERROR: " << dlerror() << std::endl;
            }
        }

        /**
         * @brief Get the Type object
         * @param functionName
         * @return shared::types::LibraryType
         */
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

        /**
         * @brief Get the Instance object
         * @param functionName
         * @return T
         */
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
