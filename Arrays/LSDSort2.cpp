#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int charAt(string *ptr, int index){
  if(index>=(*ptr).size()) return 96;
  else return (int)(*ptr)[index];
}


int main(int argc, char **argv){

  vector<string> vArray;
  vector<string> vAuxArray;
  string vInput;
  int vMaxLength=0;

  /*Open the file and read the strings*/
  ifstream vFile(argv[1]);
   if(vFile.is_open()){
       for(int i=0;getline(vFile,vInput)/*KISS*/;i++){
	 if(vInput.size()>vMaxLength) vMaxLength=vInput.size();
	 vArray.push_back(vInput);
       }
       vFile.close();
     /*This is auxillary array*/     
    vAuxArray.resize(vArray.size());
    
    /*Start LSD sorting*/
    for (int k = vMaxLength-1; k >= 0; k--)
      { 
	int count[28]={0};//assuming lower case alphabet
	//fill count array
	for (int i = 0; i < vArray.size(); i++)
	  {
	    count[charAt(&vArray[i],k)-95]++;//--> subtility1
	  }
	// cummulative count
	for (int i = 1; i < 28; ++i)
	  {
	    count[i]+=count[i-1];
	  }
	// spread the strings into the auxillary array
	for (int i = 0; i < vArray.size();i++)
	  {
	    vAuxArray[count[charAt(&vArray[i],k)-96]]=vArray[i];
	    count[charAt(&vArray[i],k)-96]+=1;
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
