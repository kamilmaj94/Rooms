#pragma once
#include "raylib.h"

class Room
{
public:
	Room();
	~Room();
	void Place();
	void Rotate();
protected:
	char buffer[50]; //for debug purposes
	int scale;
	float cornersize;
	Vector2 position;
	Color Kolor;
	Vector2 doors[4];
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