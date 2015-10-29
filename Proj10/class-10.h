/* 
 * File:   class-10.h
 * Author: jonesb63
 *
 * Created on November 24, 2014, 3:50 PM
 */

#pragma once
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<initializer_list>
using std::initializer_list;
#include <utility>
using std::pair;
#include <map>
using std::map;
#include <typeinfo>
#include <stdexcept>
using std::runtime_error;

template <class T>
class BiStack;
template <typename T>
ostream& operator<<(ostream & output, BiStack<T> & mystack);

template <class T>
class BiStack{
    public:
        //default values of 32 and 4
        BiStack(long max = 32, long initial= 4);  
        void grow_and_copy();
        BiStack operator= (T&);
        void push1(const T&);
        void push2(const T&);
        T top1();
        T top2();
        void pop1();
        void pop2();
        bool empty1();
        bool empty2();
        bool full();
        long getSize();
        T& operator[](int offset);
        T& operator=(T e);
    private:
        //declare private variables
        long initial_;
        long max_;
        long size_;
        T* pType;
        long one_pos = 0;
        long back_off = 0;
        T top1_;
        T top2_;
}; 
template <class T>
//takes in 2 longs
BiStack<T>::BiStack(long max, long initial){
    //sets initial and size to initial
    initial_ = initial;
    size_ = initial;
    //sets max to max
    max_= max;
    //sets pType to a default array of size initial
    pType = new T[initial_] ();
    //sets initial array positions to 0
    one_pos = 0;
    back_off = 0;
    //sets tops
    top1_ = pType[0];
    top2_ = pType[size_- 1 - back_off];
     
}
template <class T>
void BiStack<T>::grow_and_copy(){
    //creates a tenp pType
    T* temp = pType;
    //creates a temp size
    long temp_size = size_;
    //checks if I should double or set to max or throw error
    if(size_ * 2 <= max_){
        //if 2x is <= max size, creates a new pType as max then fills in 
        //the new pType with temp values
        pType = new T[size_ * 2] ();
        size_ = size_ * 2;
        for (int x=0; x<=one_pos ;x++){
            pType[x]=temp[x];
        }

        for (int x=0; x<= back_off; x++ ){
            pType[size_ - 1 - x] = temp[temp_size - 1 - x];
        }

    }else if (size_ != max_){
        //if not equal to max, creates a new pType as max then fills in 
        //the new pType with temp values
        pType = new T[max_] ();
        size_ = max_;
       
        for (int x=0; x<=one_pos ;x++){
            pType[x]=temp[x];
        }
        for (int x=0; x<= back_off; x++ ){
            pType[size_ - 1 - back_off] = temp[size_ - 1 - back_off];
        }
    }else{
        //throw error
        throw runtime_error("Array needs to go beyond max value."); 
    }
    //delete temp
    delete[] temp;

    
}
template <class T>   
//takes in a single item of type T
void BiStack<T>::push1(const T& item){
    //checks if full
    if(!full()){
        //if not, adds item to end of first array
        pType[one_pos]=item;
        one_pos += 1;
        top1_ = item;
    }else{
        //else it grows
        grow_and_copy();
        pType[one_pos]=item;
        one_pos += 1;
        top1_ = item;
    }
}
template <class T>
//takes in a single item of type T
void BiStack<T>::push2(const T& item){
    //checks if full
    if(!full()){
        //if not, adds item to beginning of end 
        pType[size_ - 1 - back_off]=item;
        back_off += 1;
        top2_ = item; 
    }else{
        //if full, it grows
        grow_and_copy();
        pType[size_ - 1 - back_off]=item;
        back_off += 1;
        top2_ = item; 
    }
}
template <class T>
//returns latest value of first array
T  BiStack<T>::top1(){
    return pType[one_pos - 1];
}
template <class T>
//returns the latest value of the top
T  BiStack<T>::top2(){
    return pType[size_ - 1 - back_off + 1];
}
template <class T>
//returns if full
bool BiStack<T>::full(){
    bool x = false;
    //checks if positions are equal
    if(one_pos == size_ - back_off){
        x=true;
    }

    return x;
}
template <class T>
//return size of array
long BiStack<T>::getSize(){
    //gets size
    return size_;
}
template <class T>
//return if first is empty
bool BiStack<T>::empty1(){
    //checks position of latest front value
    bool x = false;
    if(one_pos == 0){
        x = true;
    }
    return x;
}
template <class T>
//returns if second is empty
bool BiStack<T>::empty2(){
    //checks if back offset is 0
    bool x = false;
    if(back_off == 0){
        x = true;
    }
    return x;    
}
template <class T>
void BiStack<T>::pop1(){
    //checks if empty
    if(one_pos == 0){
        throw runtime_error("pop when empty!");    
    }else{
    //if not empty sets top to default
    pType[one_pos - 1] = T(); 
    one_pos -= 1;
    }
}
template <class T>
void BiStack<T>::pop2(){
    //checks if empty
    if(back_off == 0){
        throw runtime_error("pop when empty!");    
    }else{
    //if not empty sets top to default
    pType[size_ - 1 - back_off + 1] = T(); 
    back_off -= 1;
    }
}
template <class T>
//Equal operator doesn't work, changes memory of original
T& BiStack<T>::operator=(T e){
    
}
template <class T>
//takes in an int then returns that value in pType
T& BiStack<T>::operator[](int offset){
    return pType[offset];
}
template <typename T>
ostream& operator<<(ostream & output, BiStack<T> & mystack){
    //It use to work, then messed around it won't work anymore..
    //loops through elements in mystack then prints each element
    long x = mystack.getSize();
    output << "[";
    /*
        for (int i = 0; i<x; i++){
             
            if (i+1 == x){
                output << mystack[i];    
            }else{
                output << mystack[i] << ",";   
            }
        }
        output << "]" << endl; 
        output << "Top1" << mystack.top1() << endl;
        output << "Top2" << mystack.top2() << endl;
     */
        return output;
}
    

