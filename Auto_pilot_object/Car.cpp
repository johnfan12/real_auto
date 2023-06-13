#include "pch.h"
#include "Car.h"
#define PI acos(-1)
Car::Car()
{
    m_x = 0;
    m_y = 0;
    m_speed = 1; // 初始速度为 1
    // 初始化 visited 数组
    for (int i = 0; i < 800; i++)
    {
        for (int j = 0; j < 800; j++)
        {
            visited[i][j] = false;
        }
    }

}

Car::~Car()
{
}

void Car::SetStartPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Car::Move(CDC *dc, CPoint a)
{
    const int radius = 11; // 圆形范围的半径

    int maxDistance = 0;
    int farthestX = m_x;
    int farthestY = m_x; 
    for (int i = m_x - radius; i <= m_x + radius; ++i)
    {
        for (int j = m_y - radius; j <= m_y + radius; ++j)
        {
            // 计算当前点到圆心的距离
            int distance = (i - m_x) * (i - m_x) + (j - m_y) * (j - m_y);
            // 如果当前点是一个更远的点且没有走过，则更新最远点的坐标
            if (distance > maxDistance && !IsVisited(i, j) && (GetPixelColor(dc, i, j) == RGB(0,0,0)))
            {
                maxDistance = distance;
                farthestX = i;
                farthestY = j;
            }
            MarkVisited(i, j);
        }
    }

    double s = (farthestY - m_y) / sqrt((farthestX - m_x) * (farthestX - m_x) + (farthestY - m_y) * (farthestY - m_y));
    double c = (farthestX - m_x) / sqrt((farthestX - m_x) * (farthestX - m_x) + (farthestY - m_y) * (farthestY - m_y));

    
    show(c , -s, m_x, m_y, dc);
    m_x = farthestX;
    m_y = farthestY;
}

bool Car::IsVisited(int x, int y)
{

    // 检查二维数组中对应的位置是否已经被标记为已访问
    return visited[x][y];
}

void Car::MarkVisited(int x, int y)
{

    // 将二维数组中对应的位置标记为已访问
    visited[x][y] = true;
}

void Car::show(double cosx, double sinx, int x, int y, CDC* pDC)
{
    if (flag != 1)
    {
        CPen* APen, BPen;
        BPen.CreatePen(PS_SOLID, 5, RGB(240, 240, 240));
        APen = pDC->SelectObject(&BPen);
        pDC->MoveTo(CPoint(temp_x + 1, temp_y + 1));
        pDC->LineTo(CPoint(x1 + 1, y1 + 1));
        pDC->LineTo(CPoint(x2 + 1, y2 + 1));
        pDC->LineTo(CPoint(x3 + 1, y3 + 1));
        pDC->LineTo(CPoint(temp_x + 1, temp_y + 1));
        CPen* XPen, YPen;
        YPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        XPen = pDC->SelectObject(&YPen);
        pDC->MoveTo(CPoint(temp_x, temp_y));
        pDC->LineTo(CPoint(x, y));
    }
    CPen* oldPen, myPen;
    myPen.CreatePen(PS_SOLID, 3, RGB(200, 0, 0));

    oldPen = pDC->SelectObject(&myPen);
    const int length = 9;
    const int shorted = 3;
    // Calculate the x-coordinates of the end points of the lines.
    x1 = x + cosx * length;
    y1 = y - sinx * length;

    // Calculate the y-coordinates of the end points of the lines.
    x2 = x1 - sinx * shorted;
    y2 = y1 - cosx * shorted;

    x3 = x - sinx * shorted;
    y3 = y - cosx * shorted;
    // Draw the lines.
    pDC->MoveTo(CPoint(x + 1, y + 1));
    pDC->LineTo(CPoint(x1 + 1, y1 + 1));
    pDC->LineTo(CPoint(x2 + 1, y2 + 1));
    pDC->LineTo(CPoint(x3 + 1, y3 + 1));
    pDC->LineTo(CPoint(x + 1, y + 1));
    flag++;
    temp_x = x;
    temp_y = y;
}


COLORREF Car::GetPixelColor(CDC* pDC, int x, int y)
{
    return pDC->GetPixel(x, y);
}

void Car::clear_memory()
{
    for (int i = 0; i < 800; i++)
    {
        for (int j = 0; j < 800; j++)
        {
            visited[i][j] = false;
        }
    }
    flag = 1;
}
