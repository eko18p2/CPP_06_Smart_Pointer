//
// Created by mamedov on 01.10.2018.
//

#include <iostream>
using std::cout;
#ifndef INC_06_MART_PTR_SHAREDPTR_H
#define INC_06_MART_PTR_SHAREDPTR_H


template <typename T> class SharedPtr{
    T* ptr= nullptr;
    size_t *len;

    void _destroy(){
        cout<<"destroy\n";
        --*len;
        if(*len==0){
            cout<<"full destroy\n";
            delete len;
            if(ptr!= nullptr)delete ptr;
        }
    }

public:
    explicit SharedPtr(T *ptr= nullptr) : ptr(ptr) {
        this->len = new size_t(1);
    }

    SharedPtr(SharedPtr&& src){
        this->ptr=src.ptr;
        this->len=src.len;
        src.ptr = nullptr;
        src.len = new size_t(1);
    }
    SharedPtr(const SharedPtr& src){
        this->ptr=src.ptr;
        this->len=src.len;
        ++*len;
    }

    SharedPtr& operator=(T* ptr){
        _destroy();
        this->ptr=ptr;
        this->len = new size_t(1);
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& src){
        _destroy();
        this->ptr=src.ptr;
        this->len=src.len;
        src.ptr = nullptr;
        src.len = new size_t(1);
        return *this;
    }
    SharedPtr& operator=(const SharedPtr& src){
        _destroy();
        this->ptr=src.ptr;
        this->len=src.len;
        ++*len;
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



    ~SharedPtr() {
        _destroy();
    }
};



#endif //INC_06_MART_PTR_SHAREDPTR_H
