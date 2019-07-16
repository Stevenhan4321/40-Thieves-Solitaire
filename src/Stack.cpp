#include <iostream>
#include "../include/Stack.h"
#include "../include/CardTypes.h"
#include "../include/CardStack.h"
#include <vector>

// Implementation here

using namespace std;

template <class T>
Stack<T>::Stack(){
    std::vector<T> x = {};
    this->s = x;
}

template <class T>
Stack<T>::Stack(std::vector<T> s){
    this->s = s;
}

template <class T>
Stack<T> Stack<T>::push(T e) {
    std::vector<T> temp(this->s);
    temp.push_back(e);
    return Stack<T>(temp);
}

template <class T>
Stack<T> Stack<T>::pop() {
    if (this->s.empty()){
        throw out_of_range("STACK EMPTY");
    }
    std::vector<T> temp(this->s);
    temp.pop_back();
    return Stack<T>(temp);
}

template <class T>
unsigned int Stack<T>::size() {
    return this->s.size();
}

template <class T>
T Stack<T>::top() {
    if (this->s.empty()){
        throw out_of_range("STACK EMPTY");
    }
    return this->s.back();
}

template <class T>
std::vector<T> Stack<T>::toSeq(){
    return this->s;

}

template class Stack<CardT>;
// Keep this at bottom


