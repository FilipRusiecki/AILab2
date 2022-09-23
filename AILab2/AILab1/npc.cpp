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
	m_npcSprite.setPosition(1800.0f, 1800.0f);
	m_npcSprite.scale(5.0f, 5.0f);
	m_npcSprite.rotate(180);
}

void npc::npcMovement()
{

	m_npcSprite.move(0.0f, 10.0f);

}

void npc::reder(sf::RenderWindow& t_window)
{
	t_window.draw(m_npcSprite);
}


void npc::update()
{
	npcMovement();
}

