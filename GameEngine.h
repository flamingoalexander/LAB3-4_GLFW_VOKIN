#pragma once
#include "Hero.h"
#include <chrono>
#include <vector>
#include "AABB.h"
#include <iostream>
#include "Block.h"
class GameEngine
{
public:
	class PhysHero {
	public:
		Hero* hero;
		AABB* aabb;
		PhysHero(Hero* hero) {
			this->hero = hero;
			px = hero->position->x; py = hero->position->y;
			MoveRight = false;
			MoveLeft = false;
			Jump = false;
			aabb = new AABB(80, 80, new Point(px, py));
		}
		float px; float py;
		float sx = 0; float sy = 0;
		float ax = 0; float ay = 0;
		bool isStand = false;
		float gravity = 0.1;
		float resist = 0.97;





		bool MoveRight;
		bool MoveLeft;
		bool Jump;
		void UpdateHero();
		void CheckIsStand() {

			if (py + 80 > 480)
			{
				py = 480 - 80;
				sy = 0;
				isStand = true;
			}
		}
	};
	PhysHero* physhero;

	std::vector<AABB*> aabbs;


	void CheckCollision() {




		for (int i = 0; i < aabbs.size(); i++)
		{
			if (physhero->aabb->LeftUpPoint->x < aabbs[i]->LeftUpPoint->x+ aabbs[i]->width &&
				physhero->aabb->LeftUpPoint->x + physhero->aabb->width >  aabbs[i]->LeftUpPoint->x &&
				physhero->aabb->LeftUpPoint->y < aabbs[i]->LeftUpPoint->y + aabbs[i]->height &&
				physhero->aabb->height + physhero->aabb->LeftUpPoint->y > aabbs[i]->LeftUpPoint->y)
			{
				//std::cout << "Collision" << std::endl;
				if (physhero->isStand == false)
				{
					if ( (((physhero->aabb->LeftUpPoint->y + 80) - (aabbs[i]->LeftUpPoint->y)) > -5)
						&& ((std::abs((physhero->aabb->LeftUpPoint->y + 80) - (aabbs[i]->LeftUpPoint->y)) < 5)))
					{
						physhero->isStand = true;
						physhero->py = aabbs[i]->LeftUpPoint->y - 80;
						physhero->sy = 0;
					}

				}
				//RIGHT 
				if ((((physhero->aabb->LeftUpPoint->x) - (aabbs[i]->LeftUpPoint->x + aabbs[i]->width)) < 0)
					&& (((physhero->aabb->LeftUpPoint->x) - (aabbs[i]->LeftUpPoint->x + aabbs[i]->width)) > -5))
				{
					std::cout << "Collision" << std::endl;
					physhero->px = aabbs[i]->LeftUpPoint->x + aabbs[i]->width;
					physhero->sx = -physhero->sx * 0.5;
					physhero->sy = physhero->sy * 0.75;
					//physhero->px = aabbs[0]->LeftUpPoint->x + aabbs[0]->width; std::cout << "Collision on left" << std::endl;
				}


				if ((((physhero->aabb->LeftUpPoint->y) - (aabbs[i]->LeftUpPoint->y + aabbs[i]->height)) < 5) && 
					(((physhero->aabb->LeftUpPoint->y) - (aabbs[i]->LeftUpPoint->y + aabbs[i]->height)) > -5))
				{
					physhero->py = aabbs[i]->LeftUpPoint->y + aabbs[i]->height;
					physhero->sy = 0;
					std::cout << "Collision" << std::endl;
				}

				//LEFT
				if ((((physhero->aabb->LeftUpPoint->x + 80) - (aabbs[i]->LeftUpPoint->x)) > 0)
					&& (((physhero->aabb->LeftUpPoint->x + 80) - (aabbs[i]->LeftUpPoint->x)) < 5))
				{
					std::cout << "Collision" << std::endl;
					physhero->px = aabbs[i]->LeftUpPoint->x - 80;
					physhero->sx = -physhero->sx * 0.5;
					physhero->sy = physhero->sy * 0.75;
					//physhero->px = aabbs[0]->LeftUpPoint->x + aabbs[0]->width; std::cout << "Collision on left" << std::endl;
				}
			}
		}

	}






	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer;
	void Update() {
		auto currentTime = std::chrono::steady_clock::now();
		auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - TimeBuffer).count();
		if (dt >= 5)
		{
			physhero->UpdateHero();
			CheckCollision();

			for (auto e : aabbs)
			{
				e->Show();
			}
			physhero->aabb->Show();








			TimeBuffer = currentTime;
		}

	}
	GameEngine(Hero* hero, std::vector<Block*>* level) {
		this->physhero = new PhysHero(hero);
		for (auto e : *level)
		{
			aabbs.push_back(e->aabb);
		}
		//aabbs.push_back(new AABB(640, 20, new Point(0, 380)));
	}



	
};

