/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxScore
*/

#pragma once

#include "abstracts/components/TextComponent.hpp"
#include "abstracts/entity/AEntity.hpp"

using namespace shared::games::components;

class SolarFoxScore : public AEntity {
    public:
        SolarFoxScore();
        ~SolarFoxScore();

        void increaseScore(std::size_t score);
        void decreaseScore(std::size_t score);
        std::size_t getScore() const;

    private:
        std::size_t _score;
        ITextComponent::TextProps _textProps;
};
