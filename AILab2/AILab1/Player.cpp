#include "Player.h"
Player::Player()
{
	setupSprites();
}

void Player::changeDirection()
{
	if (speedX > 0 && turnRight == false)
	{
		m_playerSprite.setRotation(90);
		turnRight = true;
		turnLeft = false;
	}
	if (speedX < 0 && turnLeft == false)
	{
		m_playerSprite.setRotation(-90);
		turnRight = false;
		turnLeft = true;
	}

}

void Player::setupSprites()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\playerShip.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading player" << std::endl;
	}
	turnRight = true;
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(1500.0f, 1800.0f);
	speedX = 1;
	m_playerSprite.scale(5.0f, 5.0f);
	m_playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_playerSprite.setRotation(90);
	m_playerSprite.setOrigin(16.0f, 16.0f);

}

void Player::playerMovement()
{
	m_playerSprite.move(speedX, speedY);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		speedX--;
		changeDirection();

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		speedX++;
		changeDirection();
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	speedY--;
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	speedY++;
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	m_playerSprite.move(-10.0f, 0.0f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	m_playerSprite.move(10.0f, 0.0f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	m_playerSprite.move(0.0f, 10.0f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	m_playerSprite.move(0.0f, -10.0f);
	//}
}

void Player::reder(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}


void Player::update()
{
	playerMovement();

}
