#include "Camera.hpp"


Camera::Camera(DynamicObject* target, sf::Vector2f windowSize, sf::Vector2f worldSize)
    : target(target),
    view(sf::FloatRect(0, 0, windowSize.x, windowSize.y)),
    worldSize(worldSize) {
}

void Camera::follow(float deltaTime) {
    sf::Vector2f targetPosition = target->getSprite().getPosition();
    sf::Vector2f half(view.getSize().x / 2, view.getSize().y / 2);

    if (targetPosition.x < half.x) targetPosition.x = half.x;
    else if (targetPosition.x > worldSize.x - half.x) targetPosition.x = worldSize.x - half.x;
	targetPosition.y += target->getVelocity().y; 
    if (targetPosition.y > worldSize.y - half.y) targetPosition.y = worldSize.y - half.y;

    float smooth = 5;
    sf::Vector2f newCenter = view.getCenter() + smooth * deltaTime * (targetPosition - view.getCenter());
    view.setCenter(newCenter);
}

void Camera::apply(sf::RenderWindow& window) {
    window.setView(view);
}