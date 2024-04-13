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
		void UpdateHero();
			
	};
	PhysHero* physhero;
	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer;
	void Update() {
		auto currentTime = std::chrono::steady_clock::now();
		auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - TimeBuffer).count();
		if (dt >= 5)
		{
			physhero->UpdateHero();












			TimeBuffer = currentTime;
		}

	}
	GameEngine(Hero* hero) {
		this->physhero = new PhysHero(hero);
	}



	
};

