#include<iostream>
using namespace std;

class Shape
{
    protected:
        int width;
    public:
        int height;
    public:
        void setWidth(int w)
        {
            width=w;
        }
        void setHeight(int h)
        {
            height=h;
        }
};

class Rectangle: public Shape 
{
    public:
        int getArea()
        {
            printf("1> width=%d\n", width); //protected 可以在子类中访问
            return (width*height);
        }
};

int main()
{
    Rectangle rect;
    rect.setWidth(10);
    rect.setHeight(5);

    //printf("1> width=%d\n", rect.width); //protected 可以在子类中访问，不能在其他环境中访问
    printf("2> height=%d\n", rect.height); 

    cout << "Total area:" << rect.getArea() << endl;
    return 0;
}
