#include<iostream>
using namespace std;

int fibonacci(int x){
    
    if(x <=1){
        return x;
    }
    return fibonacci(x-1)+fibonacci(x-2);

}

int main(){
    int n;
    cout<<"Enter the number to find the fibonacci of :";
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}