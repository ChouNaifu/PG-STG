#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(int x, int y) {
    pos_.x = x;
    pos_.y = y;
    speedX_ = 10;
    speedY_ = 10;
    isAlive_ = true;
    respawnTimer_ = 180;
}
Enemy::~Enemy() {
    isAlive_ = false;
}

void Enemy::Update() {

    if (isAlive_) {
        pos_.x += speedX_;
        pos_.y += speedY_;
        if (pos_.x <= 0 || pos_.x + 50 >= 1280) {
            speedX_ *= -1;
        }
        if (pos_.y <= 0 || pos_.y + 50 >= 720) {
            speedY_ *= -1;
        }
    } else {
        if (respawnTimer_ > 0) {
            respawnTimer_--;
        } else {
            respawnTimer_ = 180;
            isAlive_ = true;
        }
    }
}

void Enemy::Draw() {
    if (isAlive_) {
        Novice::DrawBox(pos_.x, pos_.y, 50, 50, 0.0f, WHITE, kFillModeSolid);
    }
}

int Enemy::GetPosX() { return pos_.x; }
int Enemy::GetPosY() { return pos_.y; }

void Enemy::SetSpeed(int speedX, int speedY) {
    speedX_ = speedX;
    speedY_ = speedY;
}