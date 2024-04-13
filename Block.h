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
        //glTranslatef(Center->x-width/2, Center->y-width/2, 0);
        glTranslatef(position->x, position->y, 0);
        glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1); glVertex2f(position->x, position->y);
        glColor3f(1, 1, 1); glVertex2f(position->x + width, position->y);
        glColor3f(1, 1, 1); glVertex2f(position->x, position->y+height);

        glColor3f(1, 1, 1); glVertex2f(position->x, position->y);
        glColor3f(1, 1, 1); glVertex2f(position->x, position->y + height);
        glColor3f(1, 1, 1); glVertex2f(position->x + width, position->y + height);
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

