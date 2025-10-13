#include "Camera.hpp"


Camera::Camera(DynamicObject* target, sf::Vector2f windowSize, sf::Vector2f worldSize, float smooth, float velocityWeight)
    : target(target),
    view(sf::FloatRect(0, 0, windowSize.x, windowSize.y)),
    worldSize(worldSize), 
    smooth(smooth),
    velocityWeight(velocityWeight){
}

void Camera::follow() {
    sf::Vector2f targetPosition = target->getSprite().getPosition();
    sf::Vector2f half(view.getSize().x / 2, view.getSize().y / 2);

    if (targetPosition.x < half.x) targetPosition.x = half.x;
    else if (targetPosition.x > worldSize.x - half.x) targetPosition.x = worldSize.x - half.x;
	targetPosition.y += target->getVelocity().y * velocityWeight; 
    if (targetPosition.y > worldSize.y - half.y) targetPosition.y = worldSize.y - half.y;

    float smooth = 0.01f;
    sf::Vector2f newCenter = view.getCenter() + smooth * (targetPosition- view.getCenter());
    view.setCenter(newCenter);
}

void Camera::apply(sf::RenderWindow& window) {
    window.setView(view);
}