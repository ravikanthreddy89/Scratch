#include<iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char **argv){
  LL<int, string> ll;
  cout<<"Commands supported :"<<endl;
  cout<<"====================="<<endl;
  cout<<"insert <key> <value> <index>"<<endl;
  cout<<"get <key>"<<endl;
  cout<<"contains <key>"<<endl;

  string value;
  int key;
  int index;
  string command;
  
  while(true){
    cin>>command;
    if(command.compare("insert")==0){
      cin>>key;
      cin>>value;
      cin>>index;
      ll.insert(key,value,index);
    }

    if(command.compare("get")==0){
      cin>>key;
      if(ll.contains(key)==true){
	cout<<ll.get(key)<<endl;
      }
      else{
	cout<<"No such key"<<endl;
       }
    } 

    if(command.compare("quit")==0) break;
  }//end of while loop
  return 0;
 }

