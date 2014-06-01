#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void permute(string line, int k){
  if(k==line.size()) {
    cout<<line<<endl;
    return;
  }

  for(int i=k;i<line.size();i++){
    /*perform swapping*/
    swap(line[k], line[i]);
    permute(line,k+1);
    swap(line[k], line[i]);
  }
}


int main(int argc, char **argv){
  ifstream my_file("test");
  //   my_file.open("test");
  string line;
  /*check if the file is open or not*/
  if(my_file.is_open()){
    while(getline(my_file,line)){
      permute(line,0);
    }
  }
  else cout<<"Unable to open the file";
  return 0;
}
