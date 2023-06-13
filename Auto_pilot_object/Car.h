#pragma once

class Car
{
public:
    Car();
    ~Car();

    void SetStartPosition(int x, int y); // ����С���ĳ�ʼλ��
    void Move(CDC* dc, CPoint a); // �ƶ�С��
    bool IsVisited(int x, int y);
    void MarkVisited(int x, int y);
    void show(double cosx, double sinx, int x, int y, CDC* pDC);
    COLORREF GetPixelColor(CDC* pDC, int x, int y);
    void clear_memory();
    int m_x; // С����ǰ�� x ����
    int m_y; // С����ǰ�� y ����
    int m_speed; // С�����ٶ�
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