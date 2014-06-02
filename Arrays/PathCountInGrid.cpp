#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]){

  int M;
  int N;
  cout<<"Enter the dimensions:"<<endl;
  cin>>M;
  cin>>N;

  int count[M+1][N+1];
  for (int i = 1; i <= M; i++)
    {
      count[i][0]=1;
    }


  for (int i = 1; i <= N; i++)
    {
      count[0][i]=1;
    }

  for (int i =1 ; i <= M; i++)
    {
      for (int j = 1; j <= N; j++)
	{
	  count[i][j]=count[i-1][j]+count[i][j-1];
	}
    }

  cout<<"Number of paths are : "<<count[M][N]<<endl;
  return 0;
}
