#include "DynamicObject.hpp"
#include <string>

DynamicObject::DynamicObject(
    const std::string& file,
    std::map<std::string, sf::Texture>& textures,
    const sf::Vector2f& vel,
    float startX,
    float startY) : Object(file, textures, startX, startY), velocity(vel) {}

void DynamicObject::setVelocity(const sf::Vector2f& velocity) {
    DynamicObject::velocity = velocity;
}

sf::Vector2f DynamicObject::getVelocity() {
    return DynamicObject::velocity;
}

//void move(Object& object, float offsetX, float offsetY)
//{
//    sf::Vector2f position = object.getSprite().getPosition();
//    object.setPosition(position.x + offsetX, position.y + offsetY);
//}

void DynamicObject::update(float dt) {
    sprite.move(velocity * dt); 
}