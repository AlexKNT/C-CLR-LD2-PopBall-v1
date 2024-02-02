#pragma once
using namespace System::Drawing;

class Ball
{
private:
	float _x = 0;
	float _y = 0;
	Color _color = Color::Black;
	int _size = 0;
	int _frameWidth = 0;
	int _frameHeight = 0;
public:
	void draw(Graphics^ gfx);
	void setPos(int x, int y);
	Ball(int frameWidth, int frameHeight);
	Color setColor(Color color);
};

extern Ball* ball;