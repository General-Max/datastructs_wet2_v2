
#ifndef WET2_ARRAY_H
#define WET2_ARRAY_H

#include <iostream>

template<class T>
class Array
{
private:
    int m_size;
    T* m_data;
    int m_top;
    T* m_indexesArray;
    T* m_stackArray;
    const T m_defaultValue;
    bool isInitialized(int index) const;

public:
    Array(int size, T defaultValue);
    ~Array();
    T operator[](const int index) const;
    T& operator[](const int index);
    void print() const;
    int getSize() const;

};

template<class T>
bool Array<T>::isInitialized(int index) const
{
    return (m_indexesArray[index]<m_top && m_indexesArray[index]>=0 && m_stackArray[m_indexesArray[index]]==index);
}

template<class T>
Array<T>::Array(int size, T defaultValue):m_size(size), m_top(0), m_defaultValue(defaultValue)
{
    m_data = new T[size];
    m_indexesArray = new T[size];
    m_stackArray = new T[size];
}

template<class T>
Array<T>::~Array()
{
    delete[] m_data;
    delete[] m_indexesArray;
    delete[] m_stackArray;
}

template<class T>
T Array<T>::operator[](const int index) const
{
    if(isInitialized(index)){
        return m_data[index];
    }
    return m_defaultValue;
}

template<class T>
T& Array<T>::operator[](const int index)
{
    if(m_top<m_size){
        if(!isInitialized(index)){
            m_stackArray[m_top]=index;
            m_indexesArray[index]=m_top;
            m_top++;
        }
    }
    return m_data[index];
}


template<class T>
void Array<T>::print() const
{
    for(int i=0;i<m_size;i++){
        if(isInitialized(i)){
            std::cout << m_data[i];
        }
        else{
            std::cout << m_defaultValue;
        }
        if(i!=m_size-1){
            std::cout << ", ";
        }
        else{
            std::cout << "\n";
        }
    }
}

template<class T>
int Array<T>::getSize() const
{
    return this->m_size;
}

#endif //WET2_ARRAY_H
