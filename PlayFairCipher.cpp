// PLAYFAIR CIPHER ALGORITHM
#include <iostream>

using namespace std;

bool check_if_present(string a,char ch){
    for(int i=0;i<a.length();i++){
        char q = a.at(i);
        if (q==ch){
            return true;
        }
    }
    return false;
}

string encrpytToPlayfairCipher(char a,char b,char matrix[5][5]){
    string ans;
    int x1 , y1 ,x2 ,y2;
    int flag = 0;
    for(int i = 0 ; i<5;i++)
    {
        if(flag==2)
            break;
        for(int j =0 ; j<5; j++)
        {
            if(matrix[i][j]==a)
            {
                x1 =i;
                y1=j;
                flag++;
            }

            if(matrix[i][j]==b)
            {
                x2 = i;
                y2 =j;
                flag++;
            }
        }
    }
    if(x1==x2) // same row
    {
        ans.push_back(matrix[x1][(y1+1)%5]);
        ans.push_back(matrix[x2][(y2+1)%5]);
        return ans;

    }
    if(y1==y2) // same column
    {
        ans.push_back(matrix[(x1+1)%5][y1]);
        ans.push_back(matrix[(x2+1)%5][y2]);
        return ans;
    }
    ans.push_back(matrix[x1][y2]);
    ans.push_back(matrix[x2][y1]);
    return ans;
}

string decrpytToPlayfairCipher(char a,char b,char matrix[5][5]){
    string ans;
    int x1 , y1 ,x2 ,y2;
    int flag = 0;
    for(int i = 0 ; i<5;i++)
    {
        if(flag==2)
            break;
        for(int j =0 ; j<5; j++)
        {
            if(matrix[i][j]==a)
            {
                x1 =i;
                y1=j;
                flag++;
            }

            if(matrix[i][j]==b)
            {
                x2 = i;
                y2 =j;
                flag++;
            }
        }
    }
    if(x1==x2) // same row
    {
        ans.push_back(matrix[x1][(y1-1)%5]);
        ans.push_back(matrix[x2][(y2-1)%5]);
        return ans;

    }
    if(y1==y2) // same column
    {
        ans.push_back(matrix[(x1-1)%5][y1]);
        ans.push_back(matrix[(x2-1)%5][y2]);
        return ans;
    }
    ans.push_back(matrix[x1][y2]);
    ans.push_back(matrix[x2][y1]);
    return ans;
}

int main()
{
    // Taking Inputs from users
    cout<<"------Welcome To PlayFair Cipher------"<<endl;
    cout<<"Enter the Plain Text: ";
    string pt;
    cin>>pt;
    cout<<"Enter the Key: ";
    string key;
    cin>>key;

    // Sending key in matrix_key
    string matrix_key;
    for(int i=0;i<key.length();i++)
    {
        if(!check_if_present(matrix_key, key.at(i)))
        {
            matrix_key.push_back(key.at(i));
        }
        else
            continue;
    }

   char start = 'a';
    for(int i =0 ; matrix_key.length()<25;i++)
    {
        char q = (start + i -97)%26 +97;
        if(q=='j')
            continue;
        if(!check_if_present(matrix_key, q))
        {
            matrix_key.push_back(q);
        }
    }
    char matrix_array[5][5];
    int count = 0;
    for(int i =0 ; i<5;i++)
    {
        for(int j= 0 ; j<5;j++)
        {
            matrix_array[i][j] = matrix_key.at(count);
            count++;
        }
    }
    string et;
    for(int i=0;i<pt.length();i=i+2)
    {
        char pair[2];
        pair[0]= pt.at(i);
        if(pt.length()%2!=0 && i==pt.length()-1 )
        {
            pair[1] = 'x';
            continue;

        }
        pair[1] = pt.at(i+1);
        et.append(encrpytToPlayfairCipher(pair[0],pair[1],matrix_array));
    }
    cout<<"Encrypted Text is: "<<et<<endl;

    string dt;
    for(int i=0;i<et.length();i=i+2)
    {
        char pair[2];
        pair[0]= et.at(i);
        if(et.length()%2!=0 && i==et.length()-1 )
        {
            pair[1] = 'x';
            continue;

        }
        pair[1] = et.at(i+1);
        dt.append(decrpytToPlayfairCipher(pair[0],pair[1],matrix_array));
    }
    cout<<"Decrypted Text is: "<<dt;


    }
