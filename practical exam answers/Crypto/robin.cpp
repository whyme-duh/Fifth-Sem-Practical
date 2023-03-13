#include <iostream>
#include <cmath>
using namespace std;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

bool isPrime(int n, int k) {
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 4);
        int x = power(a, d, n);
        int y = 0;

        while (d != n - 1 && x != 1 && x != n - 1) {
            x = (x * x) % n;
            d *= 2;
        }

        if (x != n - 1 && d % 2 == 0)
            return false;

        d = n - 1;
    }
    return true;
}

int main() {
    int n, k;
    cout << "Enter the number to test for primality: ";
    cin >> n;
    cout << "Enter the number of iterations: ";
    cin >> k;
    if (isPrime(n, k))
        cout << n << " is prime." << endl;
    else
        cout << n << " is not prime." << endl;
    return 0;
}
