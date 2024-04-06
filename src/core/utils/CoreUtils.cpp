/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** CoreUtils
*/

#include "CoreUtils.hpp"

CoreUtils::CoreUtils()
{
}


CoreUtils::~CoreUtils()
{
}

components::IKeyboardComponent::KeyData CoreUtils::convertKey(
    const events::IKeyEvent::KeyCode &keyCode,
    const events::IKeyEvent::KeyType &keyType)
{
    components::IKeyboardComponent::KeyData data;

    std::memcpy(&data.code, &keyCode, sizeof(events::IKeyEvent::KeyCode));
    std::memcpy(&data.type, &keyType, sizeof(events::IKeyEvent::KeyType));
    return data;
}

TextAlign CoreUtils::mapTextAlign(const components::ITextComponent::TextAlign &align)
{
    switch (align) {
    case components::ITextComponent::TextAlign::CENTER:
        return shared::graphics::TextAlign::CENTER;
    case components::ITextComponent::TextAlign::LEFT:
        return shared::graphics::TextAlign::LEFT;
    case components::ITextComponent::TextAlign::RIGHT:
        return shared::graphics::TextAlign::RIGHT;
    default:
        return shared::graphics::TextAlign::CENTER;
    }
}

TextVerticalAlign CoreUtils::mapTextVerticalAlign(
    const components::ITextComponent::TextVerticalAlign &align)
{
    switch (align) {
    case components::ITextComponent::TextVerticalAlign::BOTTOM:
        return shared::graphics::TextVerticalAlign::BOTTOM;
    case components::ITextComponent::TextVerticalAlign::MIDDLE:
        return shared::graphics::TextVerticalAlign::MIDDLE;
    case components::ITextComponent::TextVerticalAlign::TOP:
        return shared::graphics::TextVerticalAlign::TOP;
    default:
        return shared::graphics::TextVerticalAlign::MIDDLE;
    }
}

bool CoreUtils::isDisplayablePressed(std::shared_ptr<components::IDisplayableComponent> displayable,
    std::shared_ptr<events::IMouseEvent> mouseEvent)
{
    Vector2f mousePos = mouseEvent->getPosition();
    auto displayablePos = displayable->getPosition();
    Vector2u displayableSize = displayable->getSize();

    if (mousePos.x >= displayablePos.x &&
    mousePos.x <= displayablePos.x + displayableSize.x &&
    mousePos.y >= displayablePos.y &&
    mousePos.y <= displayablePos.y + displayableSize.y) {
        return true;
    }
    return false;
}

shared::graphics::ISound::SoundState CoreUtils::mapSoundState(
    const shared::games::components::SoundState state)
{
    switch (state) {
    case shared::games::components::SoundState::PLAY:
        return shared::graphics::ISound::SoundState::PLAY;
    case shared::games::components::SoundState::PAUSE:
        return shared::graphics::ISound::SoundState::PAUSE;
    case shared::games::components::SoundState::STOP:
        return shared::graphics::ISound::SoundState::STOP;
    default:
        return shared::graphics::ISound::SoundState::STOP;
    }
}

bool CoreUtils::checkCollision(
    std::shared_ptr<components::ICollidableComponent> collidable1,
    std::shared_ptr<components::ICollidableComponent> collidable2)
{
    auto pos1 = collidable1->getPosition();
    auto size1 = collidable1->getSize();
    auto pos2 = collidable2->getPosition();
    auto size2 = collidable2->getSize();

    float left1 = pos1.x;
    float right1 = pos1.x + size1.x;
    float top1 = pos1.y;
    float bottom1 = pos1.y + size1.y;

    float left2 = pos2.x;
    float right2 = pos2.x + size2.x;
    float top2 = pos2.y;
    float bottom2 = pos2.y + size2.y;

    if (right1 >= left2 && left1 <= right2 && bottom1 >= top2 && top1 <= bottom2) {
        return true;
    }
    return false;
}
