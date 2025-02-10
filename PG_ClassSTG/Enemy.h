#pragma once

struct Vector2 {
    int x;
    int y;
};

class Enemy {
private:
    Vector2 pos_;
    int speedX_;
    int speedY_;
    int respawnTimer_;
public:
    Enemy(int x, int y);
    ~Enemy();
    bool isAlive_;
    void Update();
    void Draw();
    int GetPosX();
    int GetPosY();
    void SetSpeed(int speedX, int speedY);
};