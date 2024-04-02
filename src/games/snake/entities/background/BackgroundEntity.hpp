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
        BackgroundEntity();
        ~BackgroundEntity();

        const shared::games::components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        shared::games::components::ComponentsMap _components;
};

#endif /* !BACKGROUNDENTITY_HPP_ */
