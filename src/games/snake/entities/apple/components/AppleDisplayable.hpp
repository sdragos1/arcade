/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleDisplayable
*/

#ifndef APPLEDISPLAYABLE_HPP_
#define APPLEDISPLAYABLE_HPP_

#include "games/components/ITextureComponent.hpp"

class AppleDisplayable : public shared::games::components::ITextureComponent {
    public:
        explicit AppleDisplayable(const shared::games::entity::IEntity &entity);
        ~AppleDisplayable();

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

#endif /* !APPLEDISPLAYABLE_HPP_ */
