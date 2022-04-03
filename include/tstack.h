// Copyright 2022 CheginArtyom
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<class T, int size>
class T_Stack {
 private:
  T arr[20];
  int top;

 public:
  T_Stack() : top(-1) { }
  T get() const {
  return arr[top];
  }
  bool isEmpty() const {
  return top == -1;
  }
  bool isFull() const {
  return top == size - 1;
  }
  void pop() {
  if (top >= 0)
    top--;
  }
  void push(T item) {
  if (top < size - 1)
    arr[++top] = item;
  }
};
#endif  // INCLUDE_TSTACK_H_
