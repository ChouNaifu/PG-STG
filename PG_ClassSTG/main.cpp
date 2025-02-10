#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include <stdlib.h>
#include <time.h>

const char kWindowTitle[] = "GC1B_10_チョウ_ナイーフ_PG-STG";

bool CheckCollision(Bullet* bullet, Enemy* enemy) {
	if (bullet == nullptr || enemy == nullptr) {
		return false;
	}

	int bulletX = bullet->GetPosX();
	int bulletY = bullet->GetPosY();
	int enemyX = enemy->GetPosX();
	int enemyY = enemy->GetPosY();

	if (bulletX >= enemyX && bulletX <= enemyX + 50 &&
		bulletY >= enemyY && bulletY <= enemyY + 50) {
		return true;
	}

	return false;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	time_t currentTime = time(nullptr);
	srand(static_cast<unsigned int>(currentTime));

	SceneManager sceneManager;

	int score = 0;
	Player* ball = new Player;
	Enemy* enemies[5];
	for (int i = 0; i < 5; i++) {
		enemies[i] = new Enemy(rand() % 1000 + 100, rand() % 200 + 100);
		enemies[i]->SetSpeed(rand() % 20 - 10, rand() % 20 - 10);
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		sceneManager.Update(keys, preKeys);
		if (sceneManager.GetScene() == 0) {
			ball->player_.isAlive = true;
			for (int i = 0; i < 5; i++) {
				enemies[i] = new Enemy(rand() % 1000 + 100, rand() % 200 + 100);
				enemies[i]->SetSpeed(rand() % 20 - 10, rand() % 20 - 10);
			}
			score = 0;
		}

		if (sceneManager.GetScene() == 1) {
			Bullet* bullet = ball->GetBullet();

			for (int i = 0; i < 5; i++) {
				enemies[i]->Update();
				if (ball->player_.pos.x > enemies[i]->GetPosX() && ball->player_.pos.x < enemies[i]->GetPosX() + 50
					&& ball->player_.pos.y > enemies[i]->GetPosY() && ball->player_.pos.y < enemies[i]->GetPosY() + 50) {
					ball->player_.isAlive = false;
					sceneManager.SetScene(SCENE3);
				}
				if (CheckCollision(bullet, enemies[i]) && enemies[i]->isAlive_) {
					enemies[i]->isAlive_ = false;
					score++;
				}
			}
			ball->Update(keys, preKeys);
		}
		if (score >= 10) {
			sceneManager.SetScene(SCENE2);
		}
		///
		/// ↑更新処理ここまで
		///
		///
		/// ↓描画処理ここから
		///
		sceneManager.Draw();
		if (sceneManager.GetScene() == 1) {
			ball->Draw();

			for (int i = 0; i < 5; i++) {
				enemies[i]->Draw();
			}
			Novice::ScreenPrintf(20, 20, "Score: %d", score);
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
