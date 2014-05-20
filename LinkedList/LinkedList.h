#ifndef _LL_H_
#define _LL_H_

#include<iostream>
using namespace std;

template<class Key,class Value>
class LL{
  
  struct Node {
    Key key;
    Value val;
    struct Node *next;
  };

 private :
  struct Node *head;
  int sizeV;
  
 public:
  LL();
  void insert(const Key key,const Value val,const int index);
  Value get(const Key key);
  int size();
  bool contains(const Key key);
}; 

template<class Key,class Value>
LL<Key,Value>::LL(){
  head=NULL;
  sizeV=0;
}


/*insert function*/
template<class Key,class Value>
void LL<Key,Value>::insert(const Key key,const Value val,const int index){
  if(index==0){
    struct Node *temp=new struct Node;
    temp->key=key;
    temp->val=val;
    temp->next=head;
    head=temp;
    sizeV=sizeV+1;
    return;
  }
  /*This should be handled by the client. But just an extra measure*/
  if(index>sizeV){
    std::cout<<"Index out of bounds"<<endl;
    return;
  }  
  /*LinkedList index starts with 0*/
  int tempIndex=index;
  struct Node *sPtr=head;//initialize search pointer
  while(tempIndex>0){
    sPtr=sPtr->next;
    tempIndex=tempIndex-1;
  }
  struct Node *temp=new struct Node;
  temp->key=key;
  temp->val=val;
  temp->next=sPtr->next;
  sPtr=temp;
  sizeV=sizeV+1;
  return; 
}


/*contains function*/
template<class Key,class Value>
bool LL<Key, Value>::contains(const Key key){
  struct Node *sPtr=head;
  while(sPtr!=NULL){
    if(sPtr->key==key) return true;
    sPtr=sPtr->next;
  }
  return false;
}


/*get function*/
template<class Key,class Value>
Value LL<Key,Value>::get(const Key key){
  Value ret;
  struct Node *sPtr=head;
  while(sPtr->key!=key){//call contains to check if key is present
    sPtr=sPtr->next;
  }
  ret=sPtr->val;
  return ret;  
}

#endif
