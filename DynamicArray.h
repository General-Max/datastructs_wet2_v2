
#ifndef WET2_DYNAMICARRAY_H
#define WET2_DYNAMICARRAY_H

#include <iostream>

//const int RATE=2;
//const int INITIAL_SIZE = 2;

template<class T>
class DynamicArray
{
private:
    T* m_data;
    int m_size;
    int m_current;
    const T m_default;
    void expand();

public:
    explicit DynamicArray(T defaultValue);
    ~DynamicArray();
    void insert(T value);
    T& getElement(int index) const;
    void print();

};

template<class T>
DynamicArray<T>::DynamicArray(T defaultValue): m_size(INITIAL_SIZE), m_current(0), m_default(defaultValue)
{
    try{
        m_data = new T[INITIAL_SIZE];
        for(int i=0;i<m_size;i++){
            m_data[i]=m_default;
        }
    }
    catch(std::bad_alloc &e){
        delete[] m_data;
        throw e;
    }
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_data;
}

template<class T>
void DynamicArray<T>::insert(T value)
{
    if(m_current+1==m_size/2){
        expand();
    }
    m_data[m_current]=value;
    m_current++;
}

template<class T>
T& DynamicArray<T>::getElement(int index) const
{
    //check outside if legal index
    return m_data[index];
}

template<class T>
void DynamicArray<T>::expand()
{
    try{
        T* newMemory = new T[m_size*RATE];
        m_size*=RATE;
        for(int i=0;i<m_current;i++){
            newMemory[i]=m_data[i];
        }

        for(int i=m_current;i<m_size;i++){
            newMemory[i]=m_default;
        }
        delete[] m_data;
        m_data = newMemory;
    }
    catch(std::bad_alloc &e){
        throw e;
    }

}

template<class T>
void DynamicArray<T>::print()
{
    for(int i=0;i<m_size;i++){
        std::cout<<m_data[i];
        if(i<m_size-1){
            std::cout<<", ";
        }
        else{
            std::cout<<std::endl;
        }
    }
}



#endif //WET2_DYNAMICARRAY_H
