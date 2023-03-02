#include <iostream>
#include<cmath>
using namespace std;

int main(){
    //adding extra 0 in the numbers[] so that it can be easier to fetch the numbers items 
    float numbers[100] = {0,0.12, 0.01,0.23,0.28 ,0.89, 0.31,0.64,0.28,0.83,0.93,0.99,0.15,0.33,0.35,0.91,0.41,0.60,0.27, 0.75, 0.88, 0.68, 0.49,0.05, 0.43,0.95,0.58, 0.19,0.36,0.69,0.87};
    int i = 3, m =5,  N =30;
    float z = 1.96;
    float M = round((N-i)/m - 1);
    float denominator = sqrt((13*M)+7)/(12*(M+1));
    float numerator;
    float multi;
    for(int k = 0; k<=M; k++){
        cout<<"R"<<i+k*m<<":"<<numbers[i+k*m]<<endl;
        cout<<"R"<<i+(k+1)*m<<":" <<numbers[i+(k+1)*m]<<endl;
        multi += numbers[i+k*m]*numbers[i+(k+1) *m];

    }
    numerator = (1/(M+1)*multi)-0.25;
    float final = numerator/denominator;
    if(final <= z){
        cout<<"The given sequences are autocorrelated.(as z=1.96) as we have final answer as "<<final;
    }
    else{
        cout<<"The given sequences are not autocorrelated.";

    }
}