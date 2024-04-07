#pragma once
#include <string>
#include "Point.h"
class Hero
{
public:
	unsigned int texture;

	Point* position;
	int MoveXDirection;
	//GLuint* texture;
	Hero(std::string Texturefilepath) {
		loadTexture(Texturefilepath);
		this->position = new Point(100, 100);
		this->MoveXDirection = 0;
	}
	void Show();
	int width;
	int height;
private:
	void loadTexture(const std::string& filepath);
};

