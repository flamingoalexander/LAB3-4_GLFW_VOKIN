#pragma once
#include "Hero.h"
#include <chrono>
class GameEngine
{
public:
	class PhysHero {
	public:
		Hero* hero;
		PhysHero(Hero* hero) {
			this->hero = hero;
			px = hero->position->x; py = hero->position->y;
			MoveRight = false;
			MoveLeft = false;
			Jump = false;
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
		void UpdateHero() { 
			if (MoveLeft) {
				ax = -0.1;
			}
			else if (MoveRight) {
				ax = 0.1;
			} 
			else {
				ax = 0;
			}

			if (Jump && isStand) {
				sy -= 7;
			}
			
			px += sx;
			py += sy;
			sx = (sx + ax) * resist;
			if ((sx > 3))
			{
				sx = 3;
			}
			if ((sx < -3))
			{
				sx = -3;
			}
			sy = (sy + ay + gravity) * resist;
			isStand = false;
			resist = 0.99;
			hero->position->x = px; hero->position->y = py;
			if (py + 80> 480)
			{
				py = 480 - 80;
				sy = 0;
				isStand = true;
			}
		}
	};
	PhysHero* physhero;
	int gravity = 1;
	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer;
	
	void Update() {
		auto currentTime = std::chrono::steady_clock::now();
		auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - TimeBuffer).count();
		if (dt >= 10)
		{
			physhero->UpdateHero();
		}
	}
	GameEngine(Hero* hero) {
		this->physhero = new PhysHero(hero);
	}



	
};

