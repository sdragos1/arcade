/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** BackgroundEntity
*/

#ifndef BACKGROUNDENTITY_HPP_
#define BACKGROUNDENTITY_HPP_

#include "components/BackgroundDisplayable.hpp"
#include "games/IEntity.hpp"

class BackgroundEntity : public shared::games::entity::IEntity {
    public:
        /**
         * @brief Construct a new Background Entity object
         */
        BackgroundEntity();

        /**
         * @brief Destroy a new Background Entity object
         */
        ~BackgroundEntity();

        /**
         * @brief Get the Components object
         * @return const components::ComponentsMap&
         */
        const shared::games::components::ComponentsMap &getComponents(
            void) const noexcept override;

    private:
        shared::games::components::ComponentsMap _components;
};

#endif /* !BACKGROUNDENTITY_HPP_ */
