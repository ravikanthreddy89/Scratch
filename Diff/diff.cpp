#include<iostream>
#include<vector>


using namespace std;

int main(int argc, char *argv[])
{
  int order;
  cout<<"enter the order of the polynomial"<<endl;
  cin>>order;
  
  vector<int> coeffs;
  coeffs.resize(order);
 
  for (int i = order-1; i >=0; i--)
    {
      cout<<"enter the coefficient of "<<order<<"power of x"<<endl;
      cin>>coeffs[i];
    }
  
  while(order>=1){
    coeffs[order-1]=coeffs[order-1]*order;
    order=order-1;
  }

  cout<<"The derivative of above expression is :"<<endl;
  for (int i = coeffs.size()-1; i>=0; i--)
    {
      cout<<coeffs[i]<<" ";
    }
  cout<<endl;
  return 0;
}
