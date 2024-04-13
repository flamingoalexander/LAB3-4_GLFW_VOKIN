#pragma once
#include "Point.h"
#include <GLFW/glfw3.h>
#include "AABB.h"
class Block
{
public:
	Point* position;
    AABB* aabb;
	float width;
	float height;
	void Show() {
        glPushMatrix();
        glTranslatef(position->x, position->y, 0);
        glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1); glVertex2f(0, 0);
        glColor3f(1, 1, 1); glVertex2f(width, 0);
        glColor3f(1, 1, 1); glVertex2f(width, height);

        glColor3f(1, 1, 1); glVertex2f(0, 0);
        glColor3f(1, 1, 1); glVertex2f(0, height);
        glColor3f(1, 1, 1); glVertex2f(width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glEnd();
        glPopMatrix();
	}
    Block(Point* pos, float width, float height) {
        this->position = pos;
        this->height = height;
        this->width = width;
        this->aabb = new AABB(width, height, pos);
    }
};

