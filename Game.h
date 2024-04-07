#pragma once
#include "Hero.h"
#include "Game.h"
#include <GLFW/glfw3.h>
#include <chrono>
class Game
{
public:
	Hero* hero;
	void Start(int WinWidth, int WinHeight);
	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer;
	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer1;
	Game() {
		this->hero = new Hero("sprite.png");
		//start = clock();
		//dt = std::chrono::high_resolution_clock::now();
	}
	void PhysicsForHero(int WinHeight, Hero* hero);
};

