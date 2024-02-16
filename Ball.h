#pragma once
using namespace System::Drawing;

class Ball
{
private:
	float _x = 0;
	float _y = 0;
	float _dX = 0;
	float _dY = 0;
	int _color = 0x78FF0000;
	int _size = 0;
	int _frameWidth = 0;
	int _frameHeight = 0;
public:
	void draw(Graphics^ gfx);
	void setPos(int x, int y);
	Ball(int frameWidth, int frameHeight);
	int setColor(int color);
	float getdX(); // atgriež bumbiņas horizontālo ātrumu 
	float getdY(); // atgriež bumbiņas vertikālo ātrumu
	void setSpeed(float dX, float dY); // ierakstīt uz klasēs laukus jaunās ātruma vērtības 
	void move(); // pārvietot bumbiņu par vienu soļu, saskaņā ar ātrumu, un apstrādāt atlēcienus

};

extern Ball* ball;