#include "GameEngine.h"
#include "Hero.h"
void GameEngine::PhysHero::UpdateHero() {
	if (isStand)
	{
		if (MoveLeft) {
			sx = -2.5;
		}
		else if (MoveRight) {
			sx = 2.5;
		}
		else {
			ax = 0;
		}
		if (Jump) {
			sy -= 10;
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
		resist = 0.7;
		hero->position->x = px; hero->position->y = py;
	}
	else {
		if (MoveLeft) {
			ax = -0.05;
		}
		else if (MoveRight) {
			ax = 0.05;
		}
		else {
			ax = 0;
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
		this->aabb->LeftUpPoint->x = px; this->aabb->LeftUpPoint->y = py;
	}
	/*if (py + 80 > 480)
	{
		py = 480 - 80;
		sy = 0;
		isStand = true;
	}*/
	CheckIsStand();
}
