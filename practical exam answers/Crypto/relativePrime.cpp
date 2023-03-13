#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    if (gcd(a, b) == 1) {
        cout << a << " and " << b << " are relatively prime." << endl;
    } else {
        cout << a << " and " << b << " are not relatively prime." << endl;
    }
    return 0;
}
