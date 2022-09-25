#include "Alien.h"


Alien::Alien()
{

	setupSprites();
}

void Alien::update(sf::Time& t_deltaTime)
{
	randomNum();
	kinematicWander(t_deltaTime);
	
}

void Alien::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_alienSprite);
}

void Alien::randomNum()
{						//max min +1 + min
	randomInt = rand() % (10 +10 +1) + -10; //random number between -1 to 1 ;
	std::cout << "Alien rotate offset: " << randomInt << std::endl;
}

void Alien::setupSprites()
{
	if (!m_alienTexture.loadFromFile("ASSETS\\IMAGES\\alienShip.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading npc" << std::endl;
	}
	m_alienSprite.setTexture(m_alienTexture);
	//college pc 
	//m_alienSprite.setPosition(500.0f, 500.0f);
	//m_alienSprite.scale(5.0f, 5.0f);
	// my pc
	m_alienSprite.setPosition(500.0f, 500.0f);
	m_alienSprite.scale(3.0f, 3.0f);
	m_alienSprite.rotate(angle);
	m_alienSprite.setOrigin(16.0f, 16.0f);
	m_alienSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

}

void Alien::kinematicWander(sf::Time& t_deltaTime)
{

	angle = m_alienSprite.getRotation();
	angle = angle + randomInt;

	if (angle == 360.0)
	{
		angle = 0;
	}
	if (angle == 0.0)
	{
		angle = 359.0;
	}

	std::cout << "Alien angle: " << angle << std::endl;
	vel.x = speed * sin(angle * t_deltaTime.asMilliseconds() / 1000);
	vel.y = speed * -cos(angle * t_deltaTime.asMilliseconds() / 1000);
	float squareAns = sqrt((vel.x * vel.x) + (vel.y * vel.y));
	sf::Vector2f normalisedVelocity = vel / squareAns;
	m_alienSprite.move(vel);
	m_alienSprite.setRotation(angle);
}


