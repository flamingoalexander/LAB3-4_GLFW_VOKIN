#pragma once
#include <string>
#include "Point.h"
class Hero
{
public:
	unsigned int texture;

	//Point* position = new Point(50,50);

	//GLuint* texture;
	Hero(std::string Texturefilepath) {
		loadTexture(Texturefilepath);
	}
	void Show();
	int width;
	int height;
private:
	void loadTexture(const std::string& filepath);
};

