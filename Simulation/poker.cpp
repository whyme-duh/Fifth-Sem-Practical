#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int N = 1000;
    int obv[3];
    float final[3], overal_sum,expec[3], prob[3], critical_value; 
    cout<<"Enter observed value :(all different, one pair, all same)";
    for(int i = 0;i<3;i++){
        cin>>obv[i];
    }
    cout<<"Enter probability for (all different, one pair, all same) : ";
    for(int i = 0;i<3;i++){
        cin>>prob[i];
    }
    for(int i = 0;i<3;i++){
        expec[i] = N * prob[i];
        final[i] = ((obv[i] - expec[i]) * (obv[i] - expec[i]))/expec[i];
    }
    cout<<"Enter critical value : ";
    cin>>critical_value;
    for(int i = 0;i<3;i++){
        overal_sum += final[i];
    }
    cout<<"Overall Sum :"<<overal_sum;
    if(overal_sum <= critical_value){
        cout<<"\nThe generated random number is independent";
    }
    else{
        cout<<"\nThe genearted random number is not independent";
    }
    return 0;
}