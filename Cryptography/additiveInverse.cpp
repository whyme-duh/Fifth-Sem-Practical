#include <iostream>
using namespace std;

int additive_inverse(int a, int n) {
    for (int i = 1; i < n; i++) {
        if ((a*i) % n == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a, n;
    cout<<"Student roll no : 23497"<<endl;

    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter the modulo: ";
    cin >> n;
    cout << "Additive inverse of " << a << " in modulo " << n << " is: " << additive_inverse(a, n) << endl;
    return 0;
}
