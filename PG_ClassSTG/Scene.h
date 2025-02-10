#pragma once
#include <Novice.h>

enum Scene {
    SCENE0,
    SCENE1,
    SCENE2,
    SCENE3
};

class SceneManager {
private:
    Scene currentScene;
    int backGroundGraph;
    int titleGraph;
    int clearGraph;
    int gameOverGraph;
    int bgPosY;

public:
    SceneManager();
    ~SceneManager();

    void Update(char* keys, char* preKeys);
    void Draw();

    Scene GetScene();
    void SetScene(Scene newScene);
};