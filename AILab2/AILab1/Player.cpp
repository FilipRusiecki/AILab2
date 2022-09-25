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
	
		std::cout << "problem loading player" << std::endl;
	}
	turnRight = true;
	m_playerSprite.setTexture(m_playerTexture);
	speedX = 1;
	//college pc
	//m_playerSprite.setPosition(1800.0f, 1800.0f);
	//m_playerSprite.scale(5.0f, 5.0f);

	//my pc 
	m_playerSprite.setPosition(800.0f, 800.0f);
	m_playerSprite.scale(3.0f, 3.0f);
	m_playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_playerSprite.setOrigin(16.0f, 16.0f);
	//m_playerSprite.setRotation(90);
	linePoint.setRadius(2.0f);
	linePoint.setPosition(m_playerSprite.getPosition().x + 100.0f, m_playerSprite.getPosition().y);

	radius.setFillColor(sf::Color{ 107, 217, 231, 70 });
	radius.setRadius(radiusF);
	radius.setPosition(m_playerSprite.getPosition().x - radiusF, m_playerSprite.getPosition().y- radiusF);

	radiusSmaller.setFillColor(sf::Color{ 121, 1, 231, 70 });
	radiusSmaller.setRadius(radiusFSmall);
	radiusSmaller.setPosition(m_playerSprite.getPosition().x - radiusFSmall, m_playerSprite.getPosition().y - radiusFSmall);

}

void Player::playerMovement(sf::Time& t_deltaTime)
{

	//m_playerSprite.move(speedX, speedY);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	if (speedX > maxSpeedLeft)
	//	{
	//		speedX--;
	//		changeDirection();
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	if (speedX < maxSpeedRight)
	//	{
	//		speedX++;
	//		changeDirection();
	//	}
	//}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed += 0.4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed-=0.4 ; 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotation = m_playerSprite.getRotation();
		rotation -= 0.8 ;
		if (rotation == 0.0)
		{
			rotation = 359.0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotation = m_playerSprite.getRotation();
		rotation += 0.8 ;
		
		if (rotation == 360.0)
		{
			rotation = 0;
		}
	}
	vel.x = speed * sin(m_playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
	vel.y = speed * -cos(m_playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);

	m_playerSprite.move(vel);
	linePoint.move(vel);
	radius.move(vel);
	radiusSmaller.move(vel);
	m_playerSprite.setRotation(rotation);

	std::cout << "							player angle: " << rotation << std::endl;

	
}



void Player::reder(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
	t_window.draw(playerLine);
	t_window.draw(radius);
	t_window.draw(radiusSmaller);

}


void Player::update(sf::Time& t_deltaTime)
{
	playerMovement(t_deltaTime);
	
	playerLine.clear();
	sf::Vertex begin{m_playerSprite.getPosition(),sf::Color::Cyan };
	playerLine.append(begin);
	sf::Vertex end{linePoint.getPosition(), sf::Color::Cyan };
	playerLine.append(end);
}
