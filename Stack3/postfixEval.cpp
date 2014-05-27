#include<iostream>
#include<vector>

using namespace std;

int eval(int a, int b, char op){
  if(op=='+') return a+b;
  if(op=='*') return a*b;
  if(op=='-') return a-b; 
  if(op=='/') return a/b; 
}



int main(int argc, char **argv){

  int nTestCases;
  string exp;
  vector<int> stk;
  cout<<"Enter number of test cases"<<endl;
  cin>>nTestCases;
  while(nTestCases>0){
    nTestCases=nTestCases-1;
    cin>>exp;
    for (int i = 0; i < exp.size(); i++){
     	if(exp[i]=='+'|| exp[i]=='-'|| exp[i]=='*'|| exp[i]=='/'){
	  int oprndA=stk.back();
	  stk.pop_back();
	  int oprndB=stk.back();
	  stk.pop_back();
	  stk.push_back(eval(oprndB,oprndA,exp[i]));
	}
	
	if(exp[i]>=48 && exp[i]<=57){
	  stk.push_back((exp[i]-48));
	}
      }//end of for loop
    cout<<"The reuslt = "<<stk.back()<<endl;
  stk.pop_back();
  }//end of while loop

  return 0;
}
