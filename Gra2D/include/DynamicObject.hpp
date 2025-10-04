#ifndef DYNAMICOBJECT_HPP
#define DYNAMICOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Object.hpp"

class DynamicObject : public Object {
private:
	sf::Vector2f velocity;
public:
    DynamicObject(
        const std::string& file,
        std::map<std::string, sf::Texture>& textures,
        const sf::Vector2f& velocity = { 0.f, 0.f },
        float startX = 0.f,
        float startY = 0.f
    );

    ~DynamicObject() {}

    void setVelocity(const sf::Vector2f& velocity);
    sf::Vector2f getVelocity();
    void update(float deltaTime);
};
#endif 