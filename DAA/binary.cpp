#include<iostream>
#include<math.h>
using namespace std;
int binary(int a[],int val,int min,int max){
	if(max>=min){
		int index= min + (max - min)/2;
	
	if(val==a[index]){
		return index;
	}
	else{
		if(a[index]>val){
			return binary(a,val,min,index-1);
		}
		
		return binary(a,val,index+1,max);
	}
	}
	return -1;
}
int main(){
	int key,i,min,max,res;
	int a[]={1,32,41,44,50,55,61};
	printf("Enter Element to find\n");
	scanf("%d",&key);
	min=0;
	max=sizeof(a)/sizeof(a[0]);
	res=binary(a,key,min,max-1);
	if(res==-1){
		cout<<"Not found in the list";
	}
	else{
		cout<<key<<" found at "<<res<<" position"<<endl;
	}
}