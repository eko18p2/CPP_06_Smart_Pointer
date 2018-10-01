#include <iostream>
#include "SharedPtr.h"
/*
 * constructor
 * orerator*()
 * operator->()
 * destructor
 *
 * support: =,==,!=
 * */






class Point{
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        Point::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Point::y = y;
    }
};


int main() {

//    UniquePtr<Point> point(nullptr);
//
//
//    point = new Point(5,6);
//
//
//    UniquePtr<Point> p1 = std::move(point);
//    UniquePtr<Point> p2 = std::move(p1);
//
//    if(p2!=nullptr){
//        std::cout<<p2->getX()<<std::endl;
//    }


//Point points[10];
    std::shared_ptr<Point> point(new Point(2,5));

    auto point2 = point;

    std::cout<<point->getX()<<"=="<<point2->getX()<<std::endl;




    return 0;
}