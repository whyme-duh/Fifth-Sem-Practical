#include<iostream>
using namespace std;

int gcd(int , int);

int main(){
    int x,y;
    cout<<"Enter two numbers to find gcd : ";
    cin>>x>>y;
    cout<<"GCD of given numbers is "<<gcd(x,y);
    return 0;

}

int gcd(int a, int b){
    int r;
    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }
    
    while((a%b) > 0){
        r = a%b;
        a = b;
        b = r;
    }
    return b;
}