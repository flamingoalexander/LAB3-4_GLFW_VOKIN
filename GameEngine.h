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
		if (physhero->aabb->LeftUpPoint->x < aabbs[0]->LeftUpPoint->x+ aabbs[0]->width &&
			physhero->aabb->LeftUpPoint->x + physhero->aabb->width >  aabbs[0]->LeftUpPoint->x &&
			physhero->aabb->LeftUpPoint->y < aabbs[0]->LeftUpPoint->y + aabbs[0]->height &&
			physhero->aabb->height + physhero->aabb->LeftUpPoint->y > aabbs[0]->LeftUpPoint->y)
		{
			std::cout << "Collision" << std::endl;
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

