#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the plain text:";
    string pt;
    cin>>pt;
    cout<<"Enter No. of Shifts:";
    int s;
    cin>>s;
    string et;
    //For Encoding -->
    for(int i=0;i < pt.length();i++){
        char j = pt.at(i);
        if (islower(j)){
           et.push_back(((j+s-97)%26)+97);
        }
        if (isupper(j)){
           et.push_back(((j+s-65)%26)+65);
        }
    }
    cout<<"Encrypted text:  "<<et<<endl;
    string dt;
    // For Decoding -->
    for(int i=0;i < pt.length();i++){
        char j = et.at(i);
        if (islower(j)){
           dt.push_back(((j-s-97)%26)+97);
        }
        if (isupper(j)){
           dt.push_back(((j-s-65)%26)+65);
        }
    }
    cout<<"Decrypted text:  "<<dt<<endl;
}
