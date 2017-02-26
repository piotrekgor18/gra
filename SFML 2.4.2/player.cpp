#include "player.h"
#include <Windows.h>


Player::~Player() {}
Player::Player() : Human()
{

	t_image.loadFromFile(file);
	s_image.setTexture(t_image);
	s_image.setTextureRect(sf::IntRect(0, 64, 25, 32));
	s_image.setPosition(385, 285);

	
	t_talk.loadFromFile("action1.png");
	s_talk.setTexture(t_talk);

}

//konstruktor argumentowy (na razie bez sensu jest)
Player::Player(float strengh, float pace, float hp, string name, string file, bool walk, direction dir): Human(strengh, pace, hp, name, file, walk, dir)
{

	t_image.loadFromFile(file);
	s_image.setTexture(t_image);
	s_image.setPosition(385, 285);

	t_talk.loadFromFile("action1.png");
	s_talk.setTexture(t_talk);

}

void Player::move()
{
	
	//poruszanie sie
	
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dir = down;
		if (walk)
		{
			s_image.setTextureRect(sf::IntRect(30, 64, 25, 32));
			walk = 0;
		}
		else
		{
			s_image.setTextureRect(sf::IntRect(61, 64, 25, 32));
			walk = 1;
		}
		if (s_image.getPosition().y < 568)
			s_image.move(0, s_stats.pace);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dir = up;
		if (walk)
		{
			s_image.setTextureRect(sf::IntRect(30, 0, 25, 32));
			walk = 0;
		}
		else
		{
			s_image.setTextureRect(sf::IntRect(65, 0, 25, 32));
			walk = 1;
		}

		if (s_image.getPosition().y > 0)
			s_image.move(0, -s_stats.pace);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		dir = right;
		if (walk)
		{
			s_image.setTextureRect(sf::IntRect(30, 96, 25, 32));
			walk = 0;
		}
		else
		{
			s_image.setTextureRect(sf::IntRect(65, 96, 25, 32));
			walk = 1;
		}
		if (s_image.getPosition().x < 775)
			s_image.move(s_stats.pace, 0);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		dir = left;
		if (walk)
		{
			s_image.setTextureRect(sf::IntRect(30, 32, 25, 32));
			walk = 0;
		}
		else
		{
			s_image.setTextureRect(sf::IntRect(65, 32, 25, 32));
			walk = 1;
		}
		if (s_image.getPosition().x > 0)
			s_image.move(-s_stats.pace, 0);
	}

	//spoczynek
	else {
		switch (dir)
		{
		case up:
			s_image.setTextureRect(sf::IntRect(0, 0, 25, 32));
			break;
		case down:
			s_image.setTextureRect(sf::IntRect(0, 64, 25, 32));
			break;
		case right:
			s_image.setTextureRect(sf::IntRect(0, 96, 25, 32));
			break;
		case left:
			s_image.setTextureRect(sf::IntRect(0, 32, 25, 32));
			break;
		}
	}
}

void Player::action()
{
	s_talk.setPosition(s_image.getPosition() + sf::Vector2f(-20, -55));
}







//GETTERY
Sprite Player::getImage() 
{ 
	return s_image; 
}
Sprite Player::getTalk()
{
	return s_talk;
}
