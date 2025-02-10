#include "Scene.h"

SceneManager::SceneManager() {
    currentScene = SCENE0;
    backGroundGraph = Novice::LoadTexture("./Resources/images/backGround.png");
    titleGraph = Novice::LoadTexture("./Resources/images/title.png");
    clearGraph = Novice::LoadTexture("./Resources/images/clear.png");
    gameOverGraph = Novice::LoadTexture("./Resources/images/gameOver.png");
    bgPosY = 0;
}

SceneManager::~SceneManager() {}

void SceneManager::Update(char* keys, char* preKeys) {
    switch (currentScene) {
    case SCENE0:
        if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
            currentScene = SCENE1;
        }
        break;
    case SCENE1:
        bgPosY += 5;
        if (bgPosY >= 720) {
            bgPosY = 0;
        }
 
        break;
    case SCENE2:
        if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
            currentScene = SCENE0;
        }
        break;
    case SCENE3:
        if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
            currentScene = SCENE0;
        }
        break;
    }
}

void SceneManager::Draw() {
    switch (currentScene) {
    case SCENE0:
        Novice::DrawSprite(0, 0, titleGraph, 1.0f, 1.0f, 0.0f, WHITE);
        break;
    case SCENE1:
        Novice::DrawSprite(0, bgPosY, backGroundGraph, 1.0f, 1.0f, 0.0f, WHITE);
        Novice::DrawSprite(0, bgPosY - 720, backGroundGraph, 1.0f, 1.0f, 0.0f, WHITE);
        break;
    case SCENE2:
        Novice::DrawSprite(0, 0, clearGraph, 1.0f, 1.0f, 0.0f, WHITE);
        break;
    case SCENE3:
        Novice::DrawSprite(0, 0, gameOverGraph, 1.0f, 1.0f, 0.0f, WHITE);
        break;
    }
}

Scene SceneManager::GetScene() {
    return currentScene;
}

void SceneManager::SetScene(Scene newScene) {
    currentScene = newScene;
}