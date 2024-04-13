#pragma once
#include "Point.h"
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
};

