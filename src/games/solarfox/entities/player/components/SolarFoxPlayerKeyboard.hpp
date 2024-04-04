/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayerKeyboard
*/

#pragma once

#include "abstracts/components/TextureComponent.hpp"
#include "abstracts/components/AKeyboardComponent.hpp"

using namespace shared::games;

class SolarFoxPlayerKeyboard : public AKeyboardComponent {
    public:
        explicit SolarFoxPlayerKeyboard(entity::IEntity &entity);
        ~SolarFoxPlayerKeyboard();

        void onKeyPress(std::shared_ptr<IGame> ctx,
            components::IKeyboardComponent::KeyData keyData) override;

        void onKeyRelease(std::shared_ptr<IGame> ctx,
            components::IKeyboardComponent::KeyData keyData) override;

        components::IKeyboardComponent::ArrowCode getLastDirection() const;

    private:
        components::IKeyboardComponent::ArrowCode _lastDirection;
};
