#include "Game.h"
#include "Hero.h"
#include <GLFW/glfw3.h>
#include <iostream>
void Game::Start(int WinWidth, int WinHeight) {
	glPushMatrix();
	//glLoadIdentity();

	if (hero->position->y+80 < WinHeight)
	{
		hero->position->y += hero->weight;
	}
	std::cout << hero->position->y << std::endl;
	this->hero->Show();





	//glLoadIdentity();
	//glBegin(GL);
	 














	/*glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0); glVertex2f(-1, -1);
	glColor3f(0, 1, 0); glVertex2f(1, -1);
	glColor3f(0, 0, 1); glVertex2f(1, 1);
	glEnd();*/
	glPopMatrix();
}

