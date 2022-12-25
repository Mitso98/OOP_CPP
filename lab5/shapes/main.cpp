#include <iostream>
#include <windows.h>

using namespace std;

class Point
{

private:
    int m_x, m_y;

public:
    Point()
    {
    }

    Point(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    void setX(int x)
    {
        m_x = x;
    }
    void setY(int y)
    {
        m_y = y;
    }
    void setXY(int x, int y)
    {
        x = x;
        y = y;
    }
    int getX()
    {
        return m_x;
    }
    int getY()
    {
        return m_y;
    }
    void draw(int x, int y)
    {
        COORD coord = {0, 0};
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<".";
    }
    ~Point()
    {
    }
};
class Line
{
private:
    Point start_p, end_p;
public:
    Line(): start_p(), end_p()
    {
    }
    Line(int x1, int y1, int x2, int y2) : start_p(x1, y1), end_p(x2, y2)
    {
    }
    void draw()
    {
        int y1 = start_p.getY();
        int x1 = start_p.getX();
        int y2 = end_p.getY();
        int x2 = end_p.getX();

        while(x1 <= x2 || y1 <= y2)
        {
            start_p.draw(x1,y1);

            if (x1 <= x2)
                x1++;

            if(y1 <= y2)
                y1++;
        }
    }
    ~Line(){}
};
class Rect
{
private:
    Point ll, ur; // lower left, upper right
public:
    Rect(): ll(), ur(){}
    Rect(int x1, int y1, int x2, int y2): ll(x1, y1), ur(x2, y2){}
    void draw()
    {
        int x1 = ll.getX();
        int y1 = ll.getY();
        int x2 = ur.getX();
        int y2 = ur.getY();

        if (x2 <= x1 && y2 <= x2)
            return;

        while (y1 < y2)
        {
            ll.draw(x1, y1);
            y1++;
        }

        y1 = ll.getY();
        while (x1 < x2)
        {
            ll.draw(x1, y1);
            x1++;
        }

        x1 = ll.getX();
        while (x2 >= x1)
        {
            ll.draw(x2, y2);
            x2--;
        }

        x2 = ur.getX();
        while (y2 >= y1)
        {
            ll.draw(x2, y2);
            y2--;
        }
    }
};

int main()
{
    Line l1(3,3,7,7);
    Rect r1(15,15,20,20), r2(10,10,14,14);
    l1.draw();
    r1.draw();
    r2.draw();

    // push the exit message away
    COORD coord = {0, 0};
    coord.X = 0;
    coord.Y = 30;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0;
}
