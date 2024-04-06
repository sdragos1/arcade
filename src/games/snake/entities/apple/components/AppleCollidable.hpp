/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleCollidable
*/

#ifndef APPLECOLLIDABLE_HPP_
#define APPLECOLLIDABLE_HPP_

#include <iostream>
#include "games/components/ICollidableComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"
#include "../../snake_head/components/SnakeHeadCollidable.hpp"

class AppleCollidable : public shared::games::components::ICollidableComponent {
    public:
        /**
         * @brief Construct a new Apple Collidable object
         * @param entity
         */
        explicit AppleCollidable(const shared::games::entity::IEntity &entity);

        /**
         * @brief Destroy the Apple Collidable object
         */
        ~AppleCollidable();

        /**
         * @brief Get the Type object
         * @return const shared::games::components::ComponentType
         */
        const shared::games::components::ComponentType getType() const noexcept override;

        /**
         * @brief Get the entity object
         * @return const shared::games::entity::IEntity&
         */
        const shared::games::entity::IEntity &getEntity() noexcept override;

        void setPosition(Vector2f pos) noexcept;

        Vector2f &getPosition(void) noexcept override;

        Vector2u &getSize(void) noexcept override;

        /**
         * @brief On collide event handler for the component
         * @param ctx Context of the game
         * @param target Target entity
         */
        void onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target) override;

        unsigned int _score;
    private:
        const shared::games::entity::IEntity &_entity;
        Vector2f _position;
        Vector2u _size;

};

#endif /* !APPLECOLLIDABLE_HPP_ */
