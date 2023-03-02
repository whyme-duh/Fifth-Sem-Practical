#include<iostream>
using namespace std;
int main(){
	int key, flag=0,p,i;
	int a[5]={1,4,3,4,5};
	printf("Enter Element to find\n");
	scanf("%d",&key);
	for(i=0;i<5;i++){
		if(a[i]==key){
			p=i;
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("Element not found\n");
	}
	else{
		printf("Element found at %d position\n",p);
	
	}
}
