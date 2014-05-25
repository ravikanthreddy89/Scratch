#include<iostream>
#include<vector>

using namespace std;

int main(int argc,char *argv[]){
  vector<int> array;
  int size;
  int sum;
  int a=0;
  int b=0;
  bool set=false;
  cout<<"enter the size of the array:";
  cin>>size;
  array.resize(size);
  cout<<"enter the array elements ";
  for(int i=0;i<size;i++)cin>>array[i];
  cout<<"enter the value of sum:"<<endl;
  cin>>sum;
  int curr_sum=array[0];
  int start=0;
  int end=1;
  
  while(end<size){
    while(curr_sum<=sum){
      curr_sum+=array[end];
      end=end+1;
    }
    
    if(curr_sum>sum){
      if(set){
	if((b-a)>(end-1-start)){
	  b=end-1;
	  a=start;
	  curr_sum-=array[start];
	  start=start+1;
	}
      }
      else {
	b=end-1;
	a=start;
	curr_sum-=array[start];
	start=start+1;
	set=true;
      }
    }
  }
  cout<<"Start index :"<<a<<"\nEnd index:"<<b<<endl;
  return 0;
}
