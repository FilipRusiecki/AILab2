#include "npc.h"
npc::npc()
{
	setupSprites();
}

void npc::setupSprites()
{
	if (!m_npcTexture.loadFromFile("ASSETS\\IMAGES\\enemyShip.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading npc" << std::endl;
	}
	m_npcSprite.setTexture(m_npcTexture);
	//college pc
	//m_npcSprite.setPosition(1800.0f, 1800.0f);
	//m_npcSprite.scale(5.0f, 5.0f);



	//my pc
	m_npcSprite.setPosition(1500.0f, 1500.0f);
	m_npcSprite.scale(3.0f, 3.0f);
	m_npcSprite.setOrigin(16.0f, 16.0f);
	m_npcSprite.rotate(180);
}

void npc::npcMovement()
{

	m_npcSprite.move(0.0f, 10.0f);

}

void npc::boundry()
{
	//npc moving top of screen 
	if (m_npcSprite.getPosition().y > sf::VideoMode::getDesktopMode().height)
	{
		m_npcSprite.setPosition(m_npcSprite.getPosition().x, 0 - 16);
	}

}

void npc::reder(sf::RenderWindow& t_window)
{
	if (alive == true)
	{
		t_window.draw(m_npcSprite);
	}
}


void npc::update()
{
	if (alive == true)
	{
		npcMovement();
		boundry();
	}
}

