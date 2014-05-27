#include<iostream>
#include<vector>//for stack

using namespace std;

/*helper function*/
int getPrecedence(char c){
  if(c=='+' || c=='-') return 0;
  if(c=='*') return 1;
  if(c=='/') return 2;
  if(c=='(') return 17;
}



int main(int argc, char *argv[])
{
  int nTestCases;
  vector<char> stk;
  cout<<"Enter number of test cases"<<endl;
  cin>>nTestCases;
  string exp;
  while(nTestCases>0){
    nTestCases=nTestCases-1;
    cin>>exp;
    for (int i = 0; i < exp.size(); i++){
 
          if(exp[i]>=97 && exp[i]<=122) {
	    // cout<<"char"<<endl;
	    cout<<exp[i];
          }
	  //if the symbol is operand
	  if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
	    if(stk.size()==0) stk.push_back(exp[i]);
	    else{
	      int outPrecd=getPrecedence(exp[i]);
	      int inPrecd=getPrecedence(stk.back());
	      if(outPrecd<=inPrecd) {
		if(stk.back()=='('){
		  stk.push_back(exp[i]);
		}
		else {
		  cout<<stk.back();
		  stk.pop_back();
		  stk.push_back(exp[i]);
		}
	      }
	    }	    
	  }//end of operand
	  
	  //if left paranthesis 
	  if(exp[i]=='(') stk.push_back(exp[i]);
	  
	  //if right paranthesis 
	  if(exp[i]==')'){
	    while(stk.back()!='('){
	      cout<<stk.back();
	      stk.pop_back();
	    }
	    stk.pop_back();
	  }// end of RP handling
	  
    }//end of for loop
    while(stk.size()!=0){
      cout<<stk.back();
      stk.pop_back();
    }
  }//end of while loop
  cout<<endl;
  return 0;
}
