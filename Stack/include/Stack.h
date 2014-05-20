#ifndef _stack_h
#define _stack_h

class Stack{
  
 private :
  struct Node {
    int data;
    struct Node *next;
  };
  struct Node *head;
  int sizeV;
  
 public:
  Stack();
  ~Stack();
  void push(int d);
  int pop();
  bool isEmpty();
  int size();
  void print();
};

#endif
