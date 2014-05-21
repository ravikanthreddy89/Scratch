/*
Link to the problem :
http://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/
Examples:

Input: m = 3, n = 3
Output: Following matrix 
X X X
X 0 X
X X X

Input: m = 4, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 0 0 X
X X X X X

Input:  m = 5, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X

Input:  m = 6, n = 7
Output: Following matrix
X X X X X X X
X 0 0 0 0 0 X
X 0 X X X 0 X
X 0 X X X 0 X
X 0 0 0 0 0 X
X X X X X X X 
*/



#include<iostream>
#include<vector>
char c[2]={'O','X'};
using namespace std;

int main(int argc, char **argv){
  
  int m;
  int n;
  cout<<"Enter the value of m :";
  cin>>m;
  cout<<"Enter the value of n :";
  cin>>n;
  vector<vector<char> >a;
    a.resize(m);
    for (int i = 0; i < m; i++)
    {
      a[i].resize(n);
    }
 
  int x=0;
  int y=0;
  int tempM=m;
  int tempN=n;

  int ch=1;

  for(x=0,y=0; (m>=0 && n>=0); x++, y++){
   
 /*upper edge*/
  for (int i = y; i < y+n; i++)
    {
      a[x][i]=c[ch];
    }
  /*lower edge*/
  for (int i = y; i < y+n; i++)
    {
      a[x+m-1][i]=c[ch];
    }
  /*Left edge*/
  for (int i = x; i <x+m; ++i)
    {
      a[i][y]=c[ch];
    }
  /*Right edge*/
  for (int i = x; i < x+m; ++i)
    {
      a[i][y+n-1]=c[ch];
    }
    m=m-2;
    n=n-2;
    ch=ch^1;
  }
  
  
  for (int i = 0; i < tempM; i++)
    {
      for(int j=0;j<tempN;j++)
	cout<<a[i][j]<<" ";
      cout<<endl;
    }

  return 0;  
}

