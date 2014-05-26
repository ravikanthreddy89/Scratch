#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
  vector<char> stk;//stack to store the last seen delimitter
  int nTestCases;
  cout<<"Enter number of test cases "<<endl;
  cin>>nTestCases;
  string exp; 
 while(nTestCases>0){
   nTestCases=nTestCases-1;
   cin>>exp;
   int size=exp.size();
   for (int i = 0; i < size; ++i)
     {
       /*Test for opening delimiters*/
       if(exp[i]=='('|| exp[i]=='['|| exp[i]=='{') stk.push_back(exp[i]);
       /*Test for closing delimiters*/
       if(exp[i]==')'|| exp[i]==']'|| exp[i]=='}') {
	     if(stk.size()==0){
	       cout<<"Imbalanced at "<<i<<endl;
	       break;
	     }
	 
	     char c=stk.back();
	     stk.pop_back();
	     // stk.pop();
	     
	     if(exp[i]==')') {
	       cout<<"Break point"<<endl;
	       if(c=='(') continue;
	       else {
		 cout<<"Imbalanced at "<<i<<endl;
		 break;
	       }
	     }
	     
	     if(exp[i]==']') {
	       if(c=='[') continue;
	       else {
		 cout<<"Imbalanced at "<<i<<endl;
		 break;
	       }
	     }

	     if(exp[i]=='}') {
	       if(c=='{') continue;
	       else {
		 cout<<"Imbalanced at "<<i<<endl;
		 break;
	       }
	     }
	     
       }//end of closing delimiter case
      
     }//end of for loop
   if(stk.size()!=0) {
     cout<<"Imbalanced"<<endl;
     stk.clear();
   }
 }//end of while loop
  return 0;
}
