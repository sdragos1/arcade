/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

template <typename T>
DLLoader<T>::DLLoader(const std::string libraryPath) : _libraryInstance(nullptr)
{
    _libraryInstance = dlopen(libraryPath.c_str(), RTLD_LAZY);
    if (!_libraryInstance) {
        throw std::runtime_error(dlerror());
    }
}

template <typename T>
DLLoader<T>::~DLLoader()
{
    dlclose(_libraryInstance);
}

template <typename T>
T *DLLoader<T>::getInstance(const std::string functionName)
{
    T* (*createInstance)();
    createInstance = (T* (*)()) dlsym(_libraryInstance, functionName.c_str());
    if (!createInstance) {
        throw std::runtime_error(dlerror());
    }
    return createInstance();
}
