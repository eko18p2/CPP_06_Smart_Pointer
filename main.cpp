#include <iostream>
/*
 * constructor
 * orerator*()
 * operator->()
 * destructor
 *
 * support: =,==,!=
 * */


template <typename T> class UniquePtr{
    T* ptr= nullptr;
public:
    explicit UniquePtr(T *ptr= nullptr) : ptr(ptr) {}

    UniquePtr(UniquePtr&& src){
        this->ptr=src.ptr;
        src.ptr = nullptr;
    }

    UniquePtr& operator=(T* ptr){
        if(this->ptr!= nullptr) delete this->ptr;
        this->ptr=ptr;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& right){
        this->ptr=right.ptr;
        right.ptr = nullptr;
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    bool operator==(const T *right) const{
        return this->ptr == right;
    }
    bool operator!=(const T *right) const{
        return this->ptr != right;
    }



    ~UniquePtr() {
        if(ptr!= nullptr) delete ptr;
    }
};





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
    UniquePtr<Point> points[10];




    return 0;
}