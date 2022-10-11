#include<iostream>
using namespace std;

bool check_if_present(string a,char ch){
    for(int i=0;i<a.length();i+=){
        char j = a.at(i);
        if(j==ch){
            return true;
        }
    }
    return False;
}

int encryptInPlayfairCipher(string key, string pt){
    string ppt[100];
    for(int i=0;)
}
int main(){
    cout<<"-----WELCOME TO PLAYFAIR CIPHER-----";
    cout<<"Enter the key:";
    string key;
    cin>>key;
    cout<<"Enter the Plain Text:";
    string pt;
    cin>>pt;
    string key_matrix;
    
    for(int j=0; j<key.length();j++){
        if(!check_if_present(key_matrix,key.at(j))){
            key_matrix.push_back(key.at(j))
        }
    }
    
    char start = 'a';
    for(int i=0; key_matrix.length()<25;i++){
        char q = ((start+i-97)%26)+97;
        if(q=='j'){
            continue;
        }
        else{
            if(!check_if_present(key_matrix,q)){
                key_matrix.push_back(q)
            }
        }
    }
    
    string array_matrix[5][5];
    count=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)    
            array_matrix[i][j] = key_matrix.at(count);
            count++;
    }
    
    char array_matrix[5][5];
    for(int i=0; ){
        
    }
    
    et = encryptInPlayfairCipher(key, pt);
    cout<<"Encrypted Text: "<<et<<endl;
    dt = decryptInPlayfairCipher(key, et);
    cout<<"Decrypted Text: "<<dt<<endl;
}
