#include<iostream>
using namespace std;

//基类 Shape
class Shape
{
    public:
        void setWidth(int w)
        {
            width =w;
        }
        void setHeight(int h)
        {
            height=h;
        }
    protected: //变量定义在后面也不报错
        int width;
        int height;
}; //类结束要加分号

//基类 PaintCost
class PaintCost
{
    public:
        int getCost(int area)
        {
            return area*70;
        }
};


// 派生类
class Rectangle: public Shape, public PaintCost
{
    public:
        int getArea()
        {
            return width*height;
        }
};

int main()
{
    Rectangle rect;
    int area;

    rect.setHeight(50);
    rect.setWidth(70);

    area=rect.getArea();

    //输出对象的面积
    cout << "Total area: " << area << endl;

    //输出总花费
    cout << "Total cost: $"<< rect.getCost(area) << endl;

    return 0;
}