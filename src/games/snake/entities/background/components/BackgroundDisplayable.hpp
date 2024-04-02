/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** BackgroundDisplayable
*/

#ifndef BACKGROUNDDISPLAYABLE_HPP_
#define BACKGROUNDDISPLAYABLE_HPP_

#include "games/components/ITextureComponent.hpp"

class BackgroundDisplayable : public shared::games::components::ITextureComponent {
    public:
        explicit BackgroundDisplayable(const shared::games::entity::IEntity &entity);
        ~BackgroundDisplayable();

        const shared::games::components::ComponentType getType() const noexcept override;
        const shared::games::entity::IEntity &getEntity() noexcept override;

        Vector2u &getSize(void) noexcept override;
        unsigned int &getZIndex(void) noexcept override;
        shared::games::components::TextureProps &getTextureProps(void) noexcept override;
        void onMousePress(std::shared_ptr<shared::games::IGame> &ctx) override;
        void onMouseHover(std::shared_ptr<shared::games::IGame> &ctx) override;
        void onMouseRelease(std::shared_ptr<shared::games::IGame> &ctx) override;

        Vector2i &getPosition(void) noexcept override;
        Vector2i _position;

    private:
        const shared::games::entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
        shared::games::components::TextureProps _textureProps;
};

#endif /* !BackgroundDISPLAYABLE_HPP_ */
