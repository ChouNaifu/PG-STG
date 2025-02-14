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
    bool isAlive_;
public:
    Enemy(int x, int y);
    ~Enemy();
    void Update();
    void Draw();
    int GetPosX();
    int GetPosY();
    bool GetStatus();
    void SetSpeed(int speedX, int speedY);
    void SetStatus(bool status);
};