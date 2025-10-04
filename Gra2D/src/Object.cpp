#include "Object.hpp"

Object::Object(const std::string& file, std::map<std::string, sf::Texture>& textures, float startX, float startY)
{
    if (textures.find(file) == textures.end()) {
        if (!textures[file].loadFromFile("Assets/" + file + ".png"))
            throw std::runtime_error("Failed to load texture: " + file);
    }

    sprite.setTexture(textures[file]);
    sprite.setScale(2, 2);
    sprite.setPosition(startX, startY);
}

void Object::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Object::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

const sf::Sprite& Object::getSprite() const {
    return sprite;
}
