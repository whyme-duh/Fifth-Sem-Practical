#include <iostream>
using namespace std;
#define max 10

int main(){
    int i,j,n,key=0,temp=0,num[max];
    cout<<"Enter the number of items to be sorted"<<endl;
    cin>>n;
    cout<<"Enter the numbers to be sorted"<<endl;
    for(i=0;i<n;i++){
        cin>>num[i];
    }
    for(i=1;i<n;i++){
        key=num[i];
        j=i-1;
        while(j>=0 && num[j]>key){
            num[j+1]=num[j];
            j=j-1;
        }
        num[j+1]=key;
    }
    cout<<"The Sorted Array is"<<endl;
    for(i=0;i<n;i++){
        cout<<num[i]<<"\t";
    }
}
