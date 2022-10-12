#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int p = 23 ;
    int g = 9 ;
    int a = 5;
    int b = 3;
    cout<<"Private key of  alice is "<<a<<endl;
    cout<<"Private key of bob is  "<<b<<endl;
    int x = pow(g ,a ) ;
    x = x % p;
    int y = pow (g ,b) ;
    y = y % p;
    cout<<"Key generated for alice is "<<x<<endl;
    cout<<"Key generated for bob is "<<y<<endl;
    cout<<"exchange of key takes place \n";
    int alice_secret = pow(y,a);
    alice_secret = alice_secret % p;
    int bob_secret = pow(x,b);
    bob_secret = bob_secret % p ;
    cout<<"Alice secret is "<<alice_secret<<endl;
    cout<<"bob secret is "<<bob_secret<<endl;
    
}
