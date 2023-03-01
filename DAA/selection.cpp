#include <iostream>
using namespace std;
#define max 10

int main(){
    int i,j,n,min=0,temp=0,num[max];
    cout<<"Enter the number of items to be sorted"<<endl;
    cin>>n;
    cout<<"Enter the numbers to be sorted"<<endl;
    for(i=0;i<n;i++)
    {
    cin>>num[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            min=i;
            if(num[j]<num[min])
            {
                min=j;
            }
            if(min!=i)
            {
                temp=num[min];
                num[min]=num[i];
                num[i]=temp;
            }
        }
    }
    cout<<"The Sorted Array is"<<endl;
    for(i=0;i<n;i++){
        cout<<num[i]<<"\t";
    }
}
