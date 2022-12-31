#include <iostream>

using namespace std;
class GeoShape //abstract class
{
protected:
    float d1;
    float d2;
public:
    GeoShape()
    {
        cout<<"geo shape constructor"<<endl;
        d1=d2=0;
    }
    GeoShape(float x)
    {
        d1=d2=x;
    }
    GeoShape(float x, float y)
    {
        d1=x;
        d2=y;
    }
    void setD1(float x)
    {
        d1=x;
    }
    int getD1()
    {
        return d1;
    }
    void setD2(float y)
    {
        d2=y;
    }
    int getD2()
    {
        return d2;
    }
    virtual float calculateArea() = 0;

};
class Triangle : public GeoShape
{
public:
    Triangle(float x, float y) : GeoShape (x,y)
    {

    }
    float calculateArea()
    {
        return 0.5*d1*d2;
    }
};
class Rect : public GeoShape
{
public:
    Rect()
    {
        cout<<"rect constructor"<<endl;
    }
    ~Rect()
    {
        cout<<"rect distructor"<<endl;
    }
    Rect(float x, float y) : GeoShape (x,y)
    {

    }
    float calculateArea()
    {
        return d1*d2;
    }
};
class Circle : public GeoShape
{
public:
    Circle()
    {
        cout<<"this is the circle constructor"<<endl;
    }
    ~Circle()
    {
        cout<<"this is the circle distructor"<<endl;
    }
    Circle(float x) : GeoShape (x)
    {

    }
    void setRadius(float r)
    {
        d1=d2=r;
    }
    float getRadius()
    {
        return d1;
    }
    float calculateArea()
    {
        return 22.0/7*d1*d1;
    }
};
class Square : public Rect
{
public:
    Square()
    {
        cout<<"empty constructor"<<endl;
    }
    Square(float x) : Rect(x,x)
    {

    }
    void setSQDim (float x)
    {
        d1=d2=x;
    }
    float getSQDim ()
    {
        return d1;
    }
    float calculateArea()
    {
        return Rect::calculateArea();
    }
};

float sumAreas (GeoShape *p1, GeoShape *p2, GeoShape *p3)
{
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}

int main()
{
    //GeoShape g1;
    Rect r1(3,3);
    Circle c1(3);
    Triangle t1(3,4);
    cout<<"the sum of all areas is "<<sumAreas(&r1,&c1,&t1)<<endl;
    return 0;
}
