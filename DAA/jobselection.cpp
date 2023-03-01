#include <iostream>
using namespace std;
#define max 10
struct jobs{
    int job;
    int deadline;
    int profit;
    string feasibility;
};
int main(){
    int i,n,k,m,clock=1,profit=0,val;
    struct jobs j[max],temp;
    cout<<"Enter the number of jobs"<<endl;
    cin>>n;
    cout<<"collecting job datas"<<endl;
    for(i=0;i<n;i++){
        j[i].job=i+1;
        cout<<"Enter deadline and profit for job "<<i+1<<endl;
        cin>>j[i].deadline>>j[i].profit;
    }
    for(i=0;i<n-1;i++){
        for(k=i+1;k<n;k++){
            m=i;
            if(j[k].profit>j[m].profit){
                m=k;
            }
            if(m!=i){
                temp=j[m];
                j[m]=j[i];
                j[i]=temp;
            }
            }
    }
    for(i=0;i<n;i++){
        if(j[i].deadline>=clock){
            clock++;
            j[i].feasibility="Feasible";
            profit+=j[i].profit;
        }
        else{
            j[i].feasibility="Not-Feasible";
        }
    }
    cout<<"\nJob Scheduling"<<endl;
    cout<<"\nJob\t Feasibility"<<endl;
    for(i=0;i<n;i++){
        cout<<j[i].job<<"\t "<<j[i].feasibility<<endl;
    }
    cout<<endl<<"The total profit is "<<profit<<endl;;
    cout<<endl<<"The Processing Sequence is ";
    cout<<"{";
    for(i=0;i<n;i++){
        if(j[i].feasibility=="Feasible"){
            cout<<"J"<<j[i].job;
            cout<<" -> ";
            }
          }
    cout<<"}";
}
