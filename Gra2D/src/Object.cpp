#include "Object.hpp"

Object::Object(const std::string& file, std::map<std::string, sf::Texture>& textures, float startX, float startY, sf::Vector2f origin)
{
    if (textures.find(file) == textures.end()) {
        if (!textures[file].loadFromFile("Assets/" + file + ".png"))
            throw std::runtime_error("Failed to load texture: " + file);
    }

    sprite.setTexture(textures[file]);
	sprite.setOrigin(origin);
    sprite.setPosition(startX, startY);
}

void Object::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Object::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Object::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

const sf::Sprite& Object::getSprite() const {
    return sprite;
}
