/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleEntity
*/

#ifndef APPLEENTITY_HPP_
#define APPLEENTITY_HPP_

#include "components/AppleDisplayable.hpp"
#include "components/AppleCollidable.hpp"
#include "games/IEntity.hpp"

class AppleEntity : public shared::games::entity::IEntity {
    public:

        /**
         * @brief Construct a new Apple Entity object
         */
        AppleEntity();

        /**
         * @brief Destroy the Apple Entity object
         */
        ~AppleEntity();

        /**
         * @brief Get the Components object
         * @return const shared::games::components::ComponentsMap&
         */
        const shared::games::components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        shared::games::components::ComponentsMap _components;
};

#endif /* !APPLEENTITY_HPP_ */
