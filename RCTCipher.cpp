#include<iostream>
#include<string>
using namespace std;

int main(){
    cout<<"Enter The Plain Text:"<<endl;
    string pt;
    cin>>pt;
    cout<<"Enter The Seven Digit Key:"<<endl;
    string key;
    cin>>key;
    int jojo,count=0;
    jojo = pt.length()/7;
    char matrix[jojo][7],start='x';
    for(int m=0;m<=jojo;m++){
        for(int n=0;n<7;n++){
           if(count<pt.length()){
           matrix[m][n] = pt.at(count);
           count++;
           }
           else{
               matrix[m][n] = start;
           }
        }
    }
    
    string et;
    int i = 0,temp=0;
    for(int k=0;k<key.length();k++){
        temp = key[k] - '0';
        i=temp;

        
        for(int j=0;j<=jojo;j++){
            et.push_back(matrix[j][i]);
        }
        
    }
    cout<<"Encrypted Text is:"<<et<<endl;
    
    string dt;
    
}
