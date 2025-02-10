#pragma once
#include "Enemy.h"	

class Bullet {
private:
	Vector2 pos_;
	int radius_;
	int speed_;
	bool isActive_;
public:
	Bullet(int x, int y);
	~Bullet();
	void Update();
	void Draw();
	int GetPosX();
	int GetPosY();
};