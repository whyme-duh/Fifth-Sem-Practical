#include<bits/stdc++.h>
using namespace std;

int eulerTotient(int n) {
    int ans = n;

    //Iterating till the sqaure root of 'n'
    for (int i = 2; i * i <= n; i++) {
        
        //If 'i' is a factor of 'n'
        if (n % i == 0) {
            while (n % i == 0){
                n /= i;
            }
            ans -= ans / i;
        }
    }
    if (n > 1){
        ans -= ans / n;
    }
    
    return ans;
}

int main() {
    int n = 12;
    cout << eulerTotient(n) << endl;
}
