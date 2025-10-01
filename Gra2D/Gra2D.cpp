#include <SFML/Graphics.hpp>
#include <vector>

std::map<std::string, sf::Texture> textures;

std::vector<sf::Sprite> sprites;

void moveSprite(sf::Sprite& sprite, float offsetX, float offsetY)
{
    sprite.setPosition(sprite.getPosition().x + offsetX, sprite.getPosition().y + offsetY);
}

sf::Sprite stringToSprite(std::string file)
{
    if (!textures[file].loadFromFile("Assets/" + file + ".png"))
		throw std::runtime_error("Failed to load texture: " + file);

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
    sf::Sprite ludzik = stringToSprite("ludzik");
	ludzik.setPosition(-100, 240);
    sprites.push_back(ludzik);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(164,221,219));
		moveSprite(sprites[1], 0.03f, 0);
        drawAll(window);
        window.display();
    }

    return 0;
}