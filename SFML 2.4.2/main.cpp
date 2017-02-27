#include <SFML/Graphics.hpp>
#include "player.h"
#include <time.h>
#include "item.h"
#include "inventory.h"


//koment
int main()
{
	sf::RenderWindow oknoAplikacji(sf::VideoMode(800, 600), "Najlepsza gierka");
	sf::Clock clock;
	
	//PASEK
	sf::Texture pasek;
	pasek.loadFromFile("bar.png");
	sf::Sprite bar;
	bar.setTexture(pasek);
	bar.setPosition(103, 450);
	float timer = 10;
	 
	bool eq = 0;
	
	//TLO
	Texture tekstura;
	tekstura.loadFromFile("tlo.jpg");
	Sprite tlo;
	tlo.setTexture(tekstura);

	Player pl1;
	Inventory inv;

	Item rod(0, 0, 0, "rod", "items/rod.png");
	Item ladder(0, 0, 0, "ladder", "items/ladder.png");
	Item shield(0, 0, 0, "shield", "items/shield.png");

	//INVENTORY
	Texture inv_texture;
	inv_texture.loadFromFile("texture.jpg");
	Sprite inv_sprite;
	inv_sprite.setTexture(inv_texture);





	while (oknoAplikacji.isOpen())
	{
		srand(time(0));
		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{

			//ZAMKNIECIE
			if (zdarzenie.type == sf::Event::Closed)
				oknoAplikacji.close();
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				oknoAplikacji.close();

			//DODAJ DO EQ
			if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::E)
			{

				if (eq == 0)
					eq = 1;
				else
					eq = 0;
			}

			if (eq)
			{
				if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::R)
					inv.add(rod);
				if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::S)
					inv.add(shield);
				if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::L)
					inv.add(ladder);
			}
			
			else
				pl1.move();
			
		}

		oknoAplikacji.draw(tlo);
		oknoAplikacji.draw(pl1.getImage());

		//oknoAplikacji.draw(rod.getSprite());

		inv_sprite.setTextureRect(sf::IntRect(65, 0, 32 * (inv.getSize()), 42));
		inv_sprite.setPosition(sf::Vector2f(100, 100));

		if (eq)
		{
			oknoAplikacji.draw(inv_sprite);
			inv.view(oknoAplikacji);
		}

	


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			clock.restart();
			timer = clock.getElapsedTime().asSeconds(); // start zegara
			pl1.action();
		}

		if (timer < 2)
		{
			oknoAplikacji.draw(pl1.getTalk());
			oknoAplikacji.draw(bar);
			timer = clock.getElapsedTime().asSeconds();// rysowanie i pobioeranie czasu na nast obieg
		}
	
		oknoAplikacji.display();

	}
	return 0;
}