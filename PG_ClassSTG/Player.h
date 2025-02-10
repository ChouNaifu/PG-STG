#pragma once
#include "Bullet.h"
#include "Enemy.h"

struct Transform {
	Vector2 pos;
	int radius;
	int speed;
	bool isAlive;
};

class Player {
public:
	Player();
	~Player();
	Transform player_;
	Bullet* bullet_;

	void Update(char* keys, char* preKeys);
	void Draw();
	Bullet* GetBullet() const;
};