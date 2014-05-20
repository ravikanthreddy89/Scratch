#include "../include/Stack.h"
#include<iostream>
using namespace std;

int main(int argc, char **argv){
  cout<<"Welcome !!"<<endl;

  cout<<"Commands supported "<<endl;
  cout<<"========================="<<endl;
  cout<<"push <int>"<<endl;
  cout<<"pop"<<endl;
  cout<<"========================="<<endl;

  Stack stack;
 string command;
 int temp;
  while(1){
   
    cin>>command;
    if(command.compare("push")==0){
      cin>>temp;
      stack.push(temp);
    }
    if(command.compare("pop")==0){
      if(stack.isEmpty()==1) cout<<"Empty Stack"<<endl;
      else cout<<stack.pop()<<endl;
    }
    if(command.compare("print")==0){
      if(stack.isEmpty()==1) cout<<"Empty Stack"<<endl;
      else stack.print();
    }

    if(command.compare("size")==0){
      cout<<stack.size()<<endl;
    }

    if(command.compare("quit")==0){
      break;
    }
  }

}


