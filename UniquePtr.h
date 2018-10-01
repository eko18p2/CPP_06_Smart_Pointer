//
// Created by mamedov on 01.10.2018.
//

#ifndef INC_06_MART_PTR_UNIQUEPTR_H
#define INC_06_MART_PTR_UNIQUEPTR_H

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

#endif //INC_06_MART_PTR_UNIQUEPTR_H
