#include<iostream>
using namespace std;

bool check_if_present(string a,char ch){
    for(int i=0;i<a.length();i++){
        char j = a.at(i);
        if(j==ch){
            return true;
        }
    }
    return false;
}

string encryptInPlayfairCipher(char a, char b, char mat[5][5]){
    string ans;
    int x1,x2,y1,y2;
    int flag=0;
    for(int i=0;i<5;i++){
        if(flag==2){
            break;
        }
        for(int j=0;j<5;j++){
            if(mat[i][j] == a){
                x1 = i;
                y1 = j;
                flag++;
            }
            if(mat[i][j] == b){
                x2 = i;
                y2 = j;
                flag++;
            }
        }
    }
    if(x1==x2) // SAME ROWS
    {
        ans.push_back(mat[x1][(y1+1)%5]);
        ans.push_back(mat[x2][(y2+1)%5]);
        return ans;
    }
    if(y1==y2) // SAME COLUMNS
    {
        ans.push_back(mat[(x1+1)%5][y1]);
        ans.push_back(mat[(x2+1)%5][y2]);
        return ans;
    }
    ans.push_back(mat[x1][y2]);
    ans.push_back(mat[x2][y1]);
    return ans;
}

string decryptInPlayfairCipher(char a, char b, char mat[5][5]){
    string ans;
    int x1,x2,y1,y2;
    int flag=0;
    for(int i=0;i<5;i++){
        if(flag==2){
            break;
        }
        for(int j=0;j<5;j++){
            if(mat[i][j] == a){
                x1 = i;
                y1 = j;
                flag++;
            }
            if(mat[i][j] == b){
                x2 = i;
                y2 = j;
                flag++;
            }
        }
    }
    if(x1==x2) // SAME ROWS
    {
        ans.push_back(mat[x1][(y1-1)%5]);
        ans.push_back(mat[x2][(y2-1)%5]);
        return ans;
    }
    if(y1==y2) // SAME COLUMNS
    {
        ans.push_back(mat[(x1-1)%5][y1]);
        ans.push_back(mat[(x2-1)%5][y2]);
        return ans;
    }
    ans.push_back(mat[x1][y2]);
    ans.push_back(mat[x2][y1]);
    return ans;
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
            key_matrix.push_back(key.at(j));
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
                key_matrix.push_back(q);
        }
    }
    }
    char array_matrix[5][5];
    int count=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)    
            array_matrix[i][j] = key_matrix.at(count);
            count++;
    }
    
    string et;
    for(int i=0;i<pt.length();i=i+2){
        char pair[2];
        pair[0] = pt.at(i);
        if(pt.length()%2!=0 && i==pt.length()-1){
            pair[1] = 'x';
            continue;
        }
        pair[1]=pt.at(i+1);
        et.append(encryptInPlayfairCipher(pair[0],pair[1],array_matrix));
    }
    
    string dt;
    for(int i=0;i<et.length();i=i+2){
        char pair[2];
        pair[0] = pt.at(i);
        if(pt.length()%2!=0 && i==pt.length()-1){
            pair[1] = 'x';
            continue;
        }
        pair[1]=pt.at(i+1);
        dt.append(decryptInPlayfairCipher(pair[0],pair[1],array_matrix));
    }
    cout<<"Encrypted Text: "<<et<<endl;
    cout<<"Decrypted Text: "<<dt<<endl;
}
