#include "Player.h"
#include <Novice.h>

Player::Player() {
	player_.pos.x = 500;
	player_.pos.y = 500;
	player_.speed = 10;
	player_.radius = 10;
	player_.isAlive = true;
	bullet_ = nullptr;
}

Player::~Player() {
	player_.isAlive = false;
}

int Player::GetPosX() { return player_.pos.x; }
int Player::GetPosY() { return player_.pos.y; }

bool Player::GetStatus() {
	return player_.isAlive;
}

void Player::Update(char* keys, char* preKeys) {

	if (keys[DIK_W] && player_.pos.y >= 500) {
		player_.pos.y -= player_.speed;
	}
	if (keys[DIK_S] && player_.pos.y <= 700) {
		player_.pos.y += player_.speed;
	}
	if (keys[DIK_A] && player_.pos.x >= 20) {
		player_.pos.x -= player_.speed;
	}
	if (keys[DIK_D] && player_.pos.x <= 1260) {
		player_.pos.x += player_.speed;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (bullet_ == nullptr) {
			bullet_ = new Bullet(player_.pos.x, player_.pos.y);
		}
	}

	if (bullet_ != nullptr) {
		bullet_->Update();
		if (bullet_->GetPosY() < 0) {
			delete bullet_;
			bullet_ = nullptr;
		}
	}
}

void Player::Draw() {
	Novice::DrawEllipse(player_.pos.x, player_.pos.y, player_.radius, player_.radius, 0.0f, RED, kFillModeSolid);
	bullet_->Draw();
}

void Player::SetStatus(bool status) {
	player_.isAlive = status;
}

Bullet* Player::GetBullet() const {
	return bullet_;
}