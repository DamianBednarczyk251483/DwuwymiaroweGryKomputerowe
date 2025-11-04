#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "DynamicObject.hpp"

class Camera {
private:
    sf::View view;
    sf::Vector2f worldSize;
    std::vector<DynamicObject*> targets;
    float smooth;
    float velocityWeight;
    float cameraWindowHoriz;
public:
    Camera(std::vector<DynamicObject*> targets, sf::Vector2f windowSize, sf::Vector2f worldSize, float smooth = 0.9f, float velocityWeight = 0.5f, float cameraWindowHoriz = 0.2f);
    void follow();
    sf::Vector2f get_target_position();
    float get_distance();
    void apply(sf::RenderWindow& window);
};

#endif