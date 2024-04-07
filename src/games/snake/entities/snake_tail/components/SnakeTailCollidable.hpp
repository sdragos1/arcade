/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeTailCollidable
*/

#ifndef SNAKETAILCOLLIDABLE_HPP_
#define SNAKETAILCOLLIDABLE_HPP_

#include "games/components/ICollidableComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"


class SnakeTailCollidable : public shared::games::components::ICollidableComponent {
    public:
        /**
         * @brief Construct a new SnakeTail Collidable object
         * @param entity
         */
        explicit SnakeTailCollidable(const shared::games::entity::IEntity &entity);

        /**
         * @brief Destroy the SnakeTail Collidable object
         */
        ~SnakeTailCollidable();

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
        void onCollide(std::shared_ptr<shared::games::IGame> ctx,
            std::shared_ptr<shared::games::components::ICollidableComponent> target) override;

    private:
        const shared::games::entity::IEntity &_entity;
        Vector2f _position;
        Vector2u _size;
};

#endif /* !SnakeTailCOLLIDABLE_HPP_ */
