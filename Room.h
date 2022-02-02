#pragma once
#include "raylib.h"

class cRoom
{
public:
	cRoom();
	~cRoom();
	void Place();
	void Rotate();
protected:
	char Buffer[50]; //for debug purposes
	int Scale;
	float fCornersize;
	Vector2 vPosition;
	Color roomColor;
	Vector2 vDoors[4];
	enum Rotation { HORIZONTAL = 90, VERTICAL = 0 };
	struct Wall
	{
		float x;
		float y;
		float angle;
	};
private:
	Rectangle Block;
	void PutBlock(float X, float Y, float Rot, Color Kolor);
	void PutCorner(float X, float Y, Color Kolor);
};