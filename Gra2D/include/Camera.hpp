#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "DynamicObject.hpp"

class Camera {
private:
    sf::View view;
    sf::Vector2f worldSize;
    DynamicObject* target;
public:
    Camera(DynamicObject* target, sf::Vector2f windowSize, sf::Vector2f worldSize);
    void follow(float deltaTime);
    void apply(sf::RenderWindow& window);
};

#endif