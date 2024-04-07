#pragma once
#include "Hero.h"
#include "Game.h"
#include <GLFW/glfw3.h>
class Game
{
public:
	Hero* hero;
	void Start();
	Game() {
		this->hero = new Hero("sprite.png");
	}
};

