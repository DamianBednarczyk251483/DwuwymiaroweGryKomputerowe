#include <SFML/Graphics.hpp>
#include <vector>
#include "Camera.hpp"
#include "Object.hpp"
#include "DynamicObject.hpp"

std::map<std::string, sf::Texture> textures;

std::vector<Object*> objects;
std::vector<DynamicObject*> dynamicObjects;

void drawAll(sf::RenderWindow& window) {
    for (Object* object : objects) {
        object->draw(window);
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(360, 180), "Test");


    objects.push_back(new Object("polana_360x180", textures));
    objects.push_back(new Object("polana_360x180", textures,360));


    DynamicObject* player = new DynamicObject("ludzik", textures, { 50, 0 }, 100, 240, {26,45});

    objects.push_back(player);

    dynamicObjects.push_back(player);

	Camera camera(player, sf::Vector2f(360, 180), sf::Vector2f(710, 180), 0.9f, 0.2f);

	sf::Clock clock;
	float deltaTime;
	float spr = 4.0f; // do wywalenia

    sf::Vector2f mouseLastWorldPos = { 0, 0 };
    float mouseCounter = 0;
    float mouseCounterBeetweenChange = 0;

    while (window.isOpen())
    {
		deltaTime = clock.restart().asSeconds();
		//spr -= deltaTime; // do wywalenia
  //      if (spr < 0) { // do wywalenia
  //          player->setVelocity({ -330, pla }); // do wywalenia
  //      } // do wywalenia
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player->getIsOnGround())
            player->setVelocity({ player->getVelocity().x, -300 });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player->setVelocity({ -200, player->getVelocity().y });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player->setVelocity({ 200, player->getVelocity().y });
        else {
            if (player->getIsOnGround())
                player->setVelocity({ 0, player->getVelocity().y });
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePixelPos);
            player->setPosition(mouseWorldPos);
            player->setVelocity({ 0, 0});
			mouseCounter += deltaTime;
            if (mouseWorldPos != mouseLastWorldPos) {
                mouseLastWorldPos = mouseWorldPos;
                mouseCounterBeetweenChange = mouseCounter;
				mouseCounter = 0;
            }
        }
        else if (mouseCounterBeetweenChange != 0) {
            sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePixelPos);
            sf::Vector2f pom = mouseWorldPos - mouseLastWorldPos;
            player->setVelocity({ pom.x / mouseCounterBeetweenChange * 0.1f, pom.y / mouseCounterBeetweenChange * 0.1f });
            mouseCounterBeetweenChange = 0;
			mouseCounter = 0;
        }

        window.clear(sf::Color(164,221,219));

		player->update(deltaTime);

        drawAll(window);

		camera.follow();
		camera.apply(window);

        window.display();
    }

    for (Object* object : objects) {
        delete object;
    }
    objects.clear();
    dynamicObjects.clear();

    return 0;
}