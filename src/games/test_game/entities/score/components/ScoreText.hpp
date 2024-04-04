/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreText
*/

#pragma once

#include "games/components/ITextComponent.hpp"

class ScoreText : public shared::games::components::ITextComponent {
    public:
        explicit ScoreText(const std::string &content,
             const shared::games::entity::IEntity &entity);
        ~ScoreText();

        shared::games::components::ITextComponent::TextProps getTextProps() noexcept override;
        Vector2u &getSize() noexcept override;
        unsigned int &getZIndex() noexcept override;
        void onMousePress(std::shared_ptr <shared::games::IGame> ctx) override;
        void onMouseRelease(std::shared_ptr <shared::games::IGame> ctx) override;
        void onMouseHover(std::shared_ptr <shared::games::IGame> ctx) override;
        Vector2i &getPosition(void) noexcept override;
=======
        void onMousePress(std::shared_ptr<shared::games::IGame> ctx) override;
        void onMouseRelease(std::shared_ptr<shared::games::IGame> ctx) override;
        void onMouseHover(std::shared_ptr<shared::games::IGame> ctx) override;
        Vector2f &getPosition(void) noexcept override;
>>>>>>> 914b2d2 (#37 feat: also fixed the test game, the SDL2 and the SFML to make them use Vector2f instead of Vector2i for the positions)
        const shared::games::components::ComponentType getType() const noexcept override;
        const shared::games::entity::IEntity &getEntity() noexcept override;

    private:
        const std::string &_text;
        shared::games::components::ITextComponent::TextProps _props;
        Vector2u _size;
        unsigned int _zIndex;
        Vector2f _position;
        const shared::games::entity::IEntity &_entity;
};
