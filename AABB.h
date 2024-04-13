#pragma once
#include "Point.h"
#include <GLFW/glfw3.h>
class AABB
{
public:
	float width;
	float height;
	Point* LeftUpPoint;
	bool IsIntersectionOnRightBoard;
	bool IsIntersectionOnLeftBoard;
	bool IsIntersectionOnBottomBoard;
	bool IsIntersectionOnTopBoard;
	AABB(float width, float height, Point* p) {
		this->height = height;
		this->width = width;
		LeftUpPoint = new Point(p->x,p->y);
		IsIntersectionOnRightBoard = false;
		IsIntersectionOnLeftBoard = false;
		IsIntersectionOnBottomBoard = false;
		IsIntersectionOnTopBoard = false;
	}
	void Show() {
		glPushMatrix();
		glBegin(GL_LINES);
		// Верхняя линия
		glVertex2f(LeftUpPoint->x, LeftUpPoint->y);
		glVertex2f(LeftUpPoint->x + width, LeftUpPoint->y);

		// Нижняя линия
		glVertex2f(LeftUpPoint->x, LeftUpPoint->y + height);
		glVertex2f(LeftUpPoint->x + width, LeftUpPoint->y + height);

		// Левая линия
		glVertex2f(LeftUpPoint->x, LeftUpPoint->y);
		glVertex2f(LeftUpPoint->x, LeftUpPoint->y + height);

		// Правая линия
		glVertex2f(LeftUpPoint->x + width, LeftUpPoint->y);
		glVertex2f(LeftUpPoint->x + width, LeftUpPoint->y + height);
		glEnd();
		glPopMatrix();
	}
};

