/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleDisplayable
*/

#ifndef APPLEDISPLAYABLE_HPP_
#define APPLEDISPLAYABLE_HPP_

#include "games/components/ITextureComponent.hpp"

class AppleDisplayable : public ITextureComponent {
    public:
        explicit AppleDisplayable(const entity::IEntity &entity);
        ~AppleDisplayable();

        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        Vector2u &getSize(void) noexcept override;
        unsigned int &getZIndex(void) noexcept override;
        components::TextureProps &getTextureProps(void) noexcept override;
        void onMousePress(std::shared_ptr<IGame> &ctx) override;
        void onMouseHover(std::shared_ptr<IGame> &ctx) override;
        void onMouseRelease(std::shared_ptr<IGame> &ctx) override;

        Vector2i &getPosition(void) noexcept override;
        Vector2i _position;

    private:
        const entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
        components::TextureProps _textureProps;
};

1#endif /* !APPLEDISPLAYABLE_HPP_ */
