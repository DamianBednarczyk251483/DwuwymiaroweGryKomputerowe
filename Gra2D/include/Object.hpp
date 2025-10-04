#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Object {
protected:
    sf::Sprite sprite;

public:
    Object(const std::string& textureFile, std::map<std::string, sf::Texture>& textures, float startX = 0.f, float startY = 0.f);

    virtual ~Object() {}
    
    void draw(sf::RenderWindow& window) const;

    void setPosition(float x, float y);

    const sf::Sprite& getSprite() const;
};

#endif 