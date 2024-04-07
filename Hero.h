#pragma once
#include <string>
#include "Point.h"
class Hero
{
public:
	unsigned int texture;
	int speed;
	Point* position;
	int MoveXdirection;
	int direction;


	//GLuint* texture;
	Hero(std::string Texturefilepath) {
		loadTexture(Texturefilepath);
		this->position = new Point(100, 100);
		this->MoveXdirection = 0;
		this->speed = 2;
		this->direction = 1;
	}
	void Show();
	int width;
	int height;
private:
	void loadTexture(const std::string& filepath);
};

