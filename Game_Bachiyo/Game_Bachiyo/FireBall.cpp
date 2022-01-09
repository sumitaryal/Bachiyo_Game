#include "FireBall.h"
#include"ground.h"
#include"platform.h"
#include"Player.h"

void FireBall::initVariables()
{
	this->FireballImage.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\Game_Bachiyo\\images\\ground & platforms\\Mario.png");
	this->fireball.setTexture(this->FireballImage);
	this->animationPart = sf::IntRect(0.f, 0.f, 16.5f, 33.f);
	this->fired = false;
	this->fireball.setTextureRect(this->animationPart);
	
}



FireBall::FireBall()
{
	this->initVariables();
	
}

FireBall::~FireBall()
{


}


void FireBall::isFired(Player& chara)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->fired = true;
		this->fireball.setPosition(chara.getPositioning().x + 30, chara.getPositioning().y + 50);
		
	}
	
	
	if(this->fired)
	{
	
			this->fireball.move({25,0 });
			this->animateFireBall();
	}
	else
	{
		this->fireball.setPosition(chara.getPositioning().x + 30, chara.getPositioning().y + 50);
	}

}


void FireBall::FireballUpdates(Player& chara)
{

	this->isFired(chara);

}

void FireBall::animateFireBall()
{
	
	if (this->animationPart.left > 16.5) this->animationPart.left = 0;
	this->fireball.setTextureRect(this->animationPart);
	this->animationPart.left += 16.5f;
}


void FireBall::CollisionWithEnemyorSurfaces(ground& grd,platform& plat)
{
	//collision with the anything 
	for (int i = 0;i < 10; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (this->fireball.getGlobalBounds().intersects(grd.GroundSprite[i][j].getGlobalBounds()) || this->fireball.getGlobalBounds().intersects(plat.platforms[i][j].getGlobalBounds()))
			{
				this->fired = false;
			}
			
		}
	}
	

}
