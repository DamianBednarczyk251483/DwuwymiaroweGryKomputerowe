#include <SFML/Graphics.hpp>
#include <vector>

std::map<std::string, sf::Texture> textures;

std::vector<sf::Sprite> sprites;

void moveSprite(sf::Sprite& sprite, float offsetX, float offsetY)
{
	sf::Vector2f position = sprite.getPosition();
    sprite.setPosition(position.x + offsetX, position.y + offsetY);
}

sf::Sprite stringToSprite(std::string file)
{
    if (textures.find(file) == textures.end()) {
        if (!textures[file].loadFromFile("Assets/" + file + ".png"))
            throw std::runtime_error("Failed to load texture: " + file);
    }

    sf::Sprite sprite(textures[file]);
    sprite.setScale(2, 2);
    sprite.setPosition(0, 0);
    return sprite;
}

void drawAll(sf::RenderWindow& window) {
    for (auto& sprite : sprites) {
		window.draw(sprite);
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 360), "Test");


    sprites.push_back(stringToSprite("polana_360x180"));
    sprites.push_back(stringToSprite("ludzik"));
    sprites[1].setPosition(-100, 240);

	sf::Clock clock;
	float deltaTime;
	float speed = 100.0f;

    while (window.isOpen())
    {
		deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(164,221,219));
		moveSprite(sprites[1], speed * deltaTime, 0);
        drawAll(window);
        window.display();
    }

    return 0;
}