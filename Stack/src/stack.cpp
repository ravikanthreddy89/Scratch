#include<iostream>
#include "../include/Stack.h"

using namespace std;

Stack::Stack(){
  head=NULL;
  sizeV=0;
}

Stack::~Stack(){
  struct Node *temp=head;
  cout<<"bp"<<endl;
  while(temp->next!=NULL){
    head=head->next;
    delete temp;
    temp=head;
  }
  delete temp;
}
void Stack::push(int d){
  //struct Node temp = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp=new struct Node;
  temp->data=d;
  temp->next=head;
  head=temp;
  sizeV=sizeV+1;
 }

int Stack::pop(){
  int ret=head->data;
  struct Node *temp=head;
  head=temp->next;
  //free(temp);
  delete temp;
  sizeV=sizeV-1;
  return ret;
}

bool Stack::isEmpty(){
  return sizeV==0;
}

void Stack::print(){
  struct Node *temp=head;
  while(temp->next!=NULL){
    cout<<temp->data<<"  ";
    temp=temp->next;
  }
  cout<<endl;
}

int Stack::size(){
  return sizeV;
}
