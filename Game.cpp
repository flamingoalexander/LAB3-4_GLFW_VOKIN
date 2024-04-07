#include "Game.h"
#include "Hero.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
void Game::Start(int WinWidth, int WinHeight) {
	glPushMatrix();
	//glLoadIdentity();
	
	std::cout << hero->position->y << std::endl;
	this->hero->Show();
	PhysicsForHero(WinHeight, this->hero);




	//glLoadIdentity();
	//glBegin(GL);
	 














	/*glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0); glVertex2f(-1, -1);
	glColor3f(0, 1, 0); glVertex2f(1, -1);
	glColor3f(0, 0, 1); glVertex2f(1, 1);
	glEnd();*/
	glPopMatrix();
}

void Game::PhysicsForHero(int WinHeight, Hero* hero)
{
	auto currentTime = std::chrono::steady_clock::now();
	auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - TimeBuffer).count();
	if (dt >= 10)
	{
		if ((hero->position->y + 80 < WinHeight))
		{
			//if ()
		
			hero->position->y += hero->weight;
			//std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();;
		}
		TimeBuffer = currentTime;
	}
	auto dt1 = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - TimeBuffer1).count();
	if (dt1 >= 300)
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
		TimeBuffer1 = currentTime;
	}
}
