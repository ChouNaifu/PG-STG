#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(int x, int y) {
	pos_.x = x;
	pos_.y = y;
	radius_ = 5;
	speed_ = 10;
	isActive_ = true;
}

Bullet::~Bullet() {
	isActive_ = false;
}

void Bullet::Update() {
	if (this == nullptr) {
		return;
	}
	if (isActive_) {
		pos_.y -= speed_;
	}
}


void Bullet::Draw() {
	if (this == nullptr) {
		return;
	}
	if (isActive_) {
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}

int Bullet::GetPosX() { return pos_.x; }
int Bullet::GetPosY() { return pos_.y; }