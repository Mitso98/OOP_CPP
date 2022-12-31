#include <iostream>

using namespace std;
class GeoShape
{
protected:
    float d1;
    float d2;
public:
    GeoShape()
    {
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
    float calculateArea()
    {
        return 0;
    }
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

    }
    Rect(float x, float y) : GeoShape (x,y)
    {

    }
    float calculateArea()
    {
        return d1*d2;
    }
};
class Circle : private GeoShape
{
public:
    Circle()
    {
        cout<<"this is the circle constructor"<<endl;
    }
    ~Circle()
    {
        cout<<"this is the distructor"<<endl;
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
class Square : private Rect
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



int main()
{
    /*
    Triangle t1(2,3);
    cout<<"area is : "<<t1.calculateArea()<<endl;
    Rect r1(3,3);
    cout<<"area is : "<<r1.calculateArea()<<endl;
    */
    /*
    Circle c1(4);
    cout<<"circle area is "<<c1.calculateArea()<<endl;
    cout<<"violation"<<c1.setD2(3)<<endl; // error inaccessible within this context
    Square sq1;
    cout<<"violation"<<sq1.setD1(3)<<endl; // error inaccessible within this context
    sq1.setSQDim(4);
    cout<<"square area is : "<<sq1.calculateArea()<<endl;
    */
    Circle c1;
    c1.setRadius(3);
    cout<<"circle area is "<<c1.calculateArea()<<endl;
    return 0;

}
