#pragma once
#include "Hero.h"
#include "Game.h"
#include <GLFW/glfw3.h>
#include <ctime>
class Game
{
public:
	Hero* hero;
	clock_t start;
	static clock_t dt;
	void Start(int WinWidth, int WinHeight);
	Game() {
		this->hero = new Hero("sprite.png");
		start = clock();
	}
	void PhysicsForHero(int WinHeight, Hero* hero);
};

