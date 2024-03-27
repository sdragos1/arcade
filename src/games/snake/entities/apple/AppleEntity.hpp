/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleEntity
*/

#ifndef APPLEENTITY_HPP_
#define APPLEENTITY_HPP_

#include "components/AppleDisplayable.hpp"
#include "games/IEntity.hpp"

class AppleEntity : public entity::IEntity {
    public:
        AppleEntity();
        ~AppleEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;

    private:
        components::ComponentsMap _components;
};

#endif /* !APPLEENTITY_HPP_ */
