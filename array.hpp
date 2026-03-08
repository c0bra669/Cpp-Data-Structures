#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <cstdlib>
#include <iostream>
namespace DataStructures {

template<typename T, size_t S>

class Array{
public:
    using iterator = T*;
    using const_iterator = const T *;
private:
    T m_data[S];
public:
    // returns normal and const data pointer
    T* data(){return m_data;}
    const T* data() const{return m_data;}

    // normal index
    T& operator[](size_t index){
        return m_data[index];
    }
    // const index
    const T& operator[](size_t index)const{
        return m_data[index];
    }
    constexpr size_t size() const {
        return S;
    }
    void print(){
        for(size_t i=0; i < S; i++){
            std::cout<<"Array["<<i<<"] -> "<<m_data[i]<<std::endl;
        }
    }
    bool arr_cmp(Array<T,S> & other){
        for(size_t i ; i<S;i++){
            if(this[i]!=other[i]){
                return false;
            }
        }
        return true;
    }
    // Iterators
    iterator begin() { return m_data; }
    iterator end()   { return m_data + S; }

    const_iterator begin() const { return m_data; }
    const_iterator end()   const { return m_data + S; }
};

}
#endif // ARRAY_HPP
