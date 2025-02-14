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
private:
	Transform player_;
	Bullet* bullet_;
public:
	Player();
	~Player();
	int GetPosX();
	int GetPosY();
	bool GetStatus();
	void Update(char* keys, char* preKeys);
	void Draw();
	void SetStatus(bool status);
	Bullet* GetBullet() const;
};