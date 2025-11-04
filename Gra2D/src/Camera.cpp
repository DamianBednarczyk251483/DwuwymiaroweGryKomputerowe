#include "Camera.hpp"


Camera::Camera(std::vector<DynamicObject*> targets, sf::Vector2f windowSize, sf::Vector2f worldSize, float smooth, float velocityWeight, float cameraWindowHoriz)
    : targets(targets),
    view(sf::FloatRect(0, 0, windowSize.x, windowSize.y)),
    worldSize(worldSize), 
    smooth(smooth),
    velocityWeight(velocityWeight),
    cameraWindowHoriz(cameraWindowHoriz){
}

sf::Vector2f Camera::get_target_position() {
	return (targets[0]->getSprite().getPosition() + targets[1]->getSprite().getPosition()) / 2.0f;
}

float Camera::get_distance() {
	sf::Vector2f distance = targets[0]->getSprite().getPosition() - targets[1]->getSprite().getPosition();
	distance.x = abs(distance.x);
	distance.y = abs(distance.y)*360/180;
	if (distance.x < distance.y) return distance.y;
	else return distance.x;
}

void Camera::follow() {
    sf::Vector2f targetPosition = get_target_position();
	float max_distance = get_distance();
	float screen_procentage = 0.7f;
    if (max_distance > 360 * screen_procentage) {
        view.setSize({max_distance/ screen_procentage,max_distance/ screen_procentage /360*180});
        sf::Vector2f half(view.getSize().x / 2, view.getSize().y / 2);
        if (view.getCenter().y > worldSize.y - half.y)
            view.setCenter({view.getCenter().x,worldSize.y - half.y });
    }
    sf::Vector2f half(view.getSize().x / 2, view.getSize().y / 2);

    //if (abs(targetPosition.x - view.getCenter().x) < cameraWindowHoriz*half.x) targetPosition.x = view.getCenter().x;

    //if (targetPosition.x < half.x) targetPosition.x = half.x;
    //else if (targetPosition.x > worldSize.x - half.x) targetPosition.x = worldSize.x - half.x;
	//targetPosition.y += target->getVelocity().y * velocityWeight; 
    if (targetPosition.y > worldSize.y - half.y) targetPosition.y = worldSize.y - half.y;

    float smooth = 0.01f;
    sf::Vector2f newCenter = view.getCenter() + smooth * (targetPosition- view.getCenter());
    view.setCenter(newCenter);
}

void Camera::apply(sf::RenderWindow& window) {
    window.setView(view);
}