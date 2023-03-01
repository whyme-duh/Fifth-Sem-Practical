#include<iostream>
using namespace std;

int multiInverse(int , int);

int main(){
    int a, m;
    cout<<"Student roll no : 23497"<<endl;
    cout<<"Enter a :";
    cin>>a;
    cout<<"Enter modulo m:";
    cin>>m;
    cout<<"The multiple inverse of the given input and modulo is : "<< multiInverse(a,m);
    return 0;
}

int multiInverse(int x, int y){
    for(int i =0; i < y ;i++){
        if((x % y) * (i % y) % y == 1){
            return i;
        }
    }  
    return 0;
}