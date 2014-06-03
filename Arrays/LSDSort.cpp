#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(int argc, char **argv){

  vector<string> vArray;
  vector<string> vAuxArray;
  string vInput;
  int vStringLength;

  /*Open the file and read the strings*/
  ifstream vFile(argv[1]);
   if(vFile.is_open()){
     vFile>>vStringLength;
     if(vStringLength==0){
       vFile.close();
       return 0;
     }
     else {
       getline(vFile,vInput);// purge any new line characters 
       for(int i=0;getline(vFile,vInput)/*KISS*/;i++){
	 vArray.push_back(vInput);
       }
       vFile.close();
     }
     /*This is auxillary array*/     
    vAuxArray.resize(vArray.size());
    
    /*Start LSD sorting*/
    for (int k = vStringLength-1; k >= 0; k--)
      { 
	//	cout<<k<<endl;
	int count[27]={0};//assuming lower case alphabet
	//fill count array
	for (int i = 0; i < vArray.size(); i++)
	  {
	    count[vArray[i][k]-96]++;//--> subtility1
	  }
	// cummulative count
	for (int i = 1; i < 26; ++i)
	  {
	    count[i]+=count[i-1];
	  }
	// spread the string into the auxillary array
	for (int i = 0; i < vArray.size();i++)
	  {
	    vAuxArray[count[vArray[i][k]-97]]=vArray[i];//--> subtility2
	    count[vArray[i][k]-97]+=1;
	  }

	// copy the elements back into array from aux array
	for (int i = 0; i < vArray.size(); i++)
	  {
	    vArray[i]=vAuxArray[i];
	  }
      }

    for (int i = 0; i < vArray.size(); i++)
      {
	cout<<vArray[i]<<endl;
      }
  }
  else cout<<"Unable to open file."<<endl;
  return 0;
}
