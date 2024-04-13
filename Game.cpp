#include "Game.h"
#include "Hero.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
void Game::Update(int WinWidth, int WinHeight) {
	glPushMatrix();
	//glLoadIdentity();
	
	//std::cout << hero->position->y << std::endl;



	this->hero->Show();
	LogicForHero(this->hero);
	for (auto e : *level)
	{
		e->Show();
	}
		



	ge->Update();










	

	glPopMatrix();
}

void Game::LogicForHero(Hero* hero)
{
	auto currentTime = std::chrono::steady_clock::now();
	auto dt1 = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - TimeBuffer).count();
	if (dt1 >= 200)
	{
		if ((hero->MoveXdirection != 0))
		{
			if ((hero->HeroStatement == 7))
			{
				hero->HeroStatement = 1;
			}
			else {
				hero->HeroStatement += 1;
			}
		}
		TimeBuffer = currentTime;
	}
}
