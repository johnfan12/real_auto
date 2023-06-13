#pragma once

class Car
{
public:
    Car();
    ~Car();

    void SetStartPosition(int x, int y); // 设置小车的初始位置
    void Move(CDC* dc, CPoint a); // 移动小车
    bool IsVisited(int x, int y);
    void MarkVisited(int x, int y);
    void show(double cosx, double sinx, int x, int y, CDC* pDC);
    COLORREF GetPixelColor(CDC* pDC, int x, int y);
    void clear_memory();
    int m_x; // 小车当前的 x 坐标
    int m_y; // 小车当前的 y 坐标
    int m_speed; // 小车的速度
private:
    double next_angle;
    double x1;
    double x2;
    double x3;
    double y1;
    double y2;
    double y3;
    double temp_x;
    double temp_y;
    double temp2_x;
    double temp2_y;
    int flag = 1;
    bool visited[800][800];
};