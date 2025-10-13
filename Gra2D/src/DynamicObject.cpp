#include "DynamicObject.hpp"
#include <string>

DynamicObject::DynamicObject(
    const std::string& file,
    std::map<std::string, sf::Texture>& textures,
    const sf::Vector2f& vel,
    float startX,
    float startY,
    sf::Vector2f origin) : Object(file, textures, startX, startY, origin), velocity(vel) {}

void DynamicObject::setVelocity(const sf::Vector2f& velocity) {
    DynamicObject::velocity = velocity;
    if (velocity.x > 0) {
        sprite.setScale(1.f, 1.f);
    }
    else if (velocity.x < 0)
    {
		sprite.setScale(-1.f, 1.f);
    }
}

sf::Vector2f DynamicObject::getVelocity() {
    return DynamicObject::velocity;
}

void DynamicObject::update(float deltatime) {
    if (sprite.getPosition().y <= 165) {
        velocity.y += 98.1f * deltatime * 3;
		isOnGround = false;
	}
    else {
		isOnGround = true;
        velocity.y = 0;
		sprite.setPosition(sprite.getPosition().x, 165);
    }
    sprite.move(velocity * deltatime);
}

bool DynamicObject::getIsOnGround() {
    return isOnGround;
}