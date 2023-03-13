#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int totient(int n) {
    int result = n;
    for (int i = 2; i <= n; i++) {
        if (gcd(i, n) == 1) {
            result--;
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    cout << "Totient of " << n << " is: " << totient(n) << endl;
    return 0;
}
