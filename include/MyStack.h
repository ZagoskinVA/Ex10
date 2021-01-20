// Copyright 2020 sccc
#include <string>
#include <iostream>
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <typename T>
class MyStack {

private:
T* stackPtr;
int size;
int top;
public:
explicit MyStack(int size);
explicit MyStack(const MyStack& stack);
~MyStack();
T get() const;
T pop();
bool push(T value);
bool isFull() const;
bool isEmpty() const;
};

#endif  // INCLUDE_MYSTACK_H_


template <typename T>
MyStack<T>::MyStack(int size) {
if (size > 0) {
this->size = size;
stackPtr = new T[size];
top = -1;
}
}

template <typename T>
MyStack<T>::MyStack(const MyStack& stack) {
size = stack.size;
top = stack.top;
stackPtr = new T[size];
for (int i = 0; i < size; i++)
stackPtr[i] = stack.stackPtr[i];
}

template <typename T>
MyStack<T>::~MyStack() {
delete[] stackPtr;
}

template <typename T>
bool MyStack<T>::push(T value) {
if (top == size - 1) {
return false;
}
top++;
stackPtr[top] = value;
return true;
}

template <typename T>
T MyStack<T>::pop() {
if (top == -1)
throw - 1;
top--;
return stackPtr[top + 1];
}

template <typename T>
T MyStack<T>::get() const {
if (top == -1)
throw - 1;
return stackPtr[top];
}

template <typename T>
bool MyStack<T>::isEmpty()const {
if (top == -1)
return true;
return false;
}

template <typename T>
bool MyStack<T>::isFull()const {
if (top + 1 == size)
return true;
return false;
}
