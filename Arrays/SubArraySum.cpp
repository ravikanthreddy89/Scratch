#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> a;
  int size;
  int sum;
  cout<<"enter the size of the array"<<endl;
  cin>>size;
  cout<<"enter the sum :";
  cin>>sum;
  a.resize(size);
  for (int i = 0; i < size; i++)
    {
      cin>>a[i];
    }
  int start=0;
  int end=1;
  int curr_sum=a[start];

  while(curr_sum!=sum || end !=size){
    while(curr_sum<sum){
      curr_sum+=a[end];
      end++;
    }
    if(curr_sum==sum){
      cout<<"the sub array indices = "<<start<<" "<<(end-1)<<" "<<endl;
      return 0;
    }
    
    while(curr_sum>sum){
      curr_sum-=a[start];
      start++;
    }
  }
  return 0;
}
