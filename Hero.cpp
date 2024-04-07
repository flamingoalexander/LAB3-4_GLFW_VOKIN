#include "Hero.h"
#include "stb_image.h"
#include <iostream>
#include <GLFW/glfw3.h>
void Hero::loadTexture(const std::string& filepath) {
	int channels = 4;
	int width = 2;
	int height = 2;
	unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
			      0, channels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);

}
void Hero::Show() {
	glTranslatef(50, 50, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glColor3f(1, 1, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	float textureCoord[] = {1.0/8,0, 0,0, 0,1.0/3, 1.0 / 8, 1.0/3 };
	float vertex[] = { 0, 0, 0, 80, 0, 0, 80, 80, 0, 0, 80, 0 };
	glPushMatrix();
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, textureCoord);

		glVertexPointer(3, GL_FLOAT, 0, vertex);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}
