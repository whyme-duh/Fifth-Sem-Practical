#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int power(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

void findPrimitive(int p) {
    if (p == 2 || p == 3) {
        cout << "Primitive root of " << p << " is: " << 2 << endl;
        return;
    }
    int phi = p - 1;
    vector<int> factors;
    for (int i = 2; i <= sqrt(phi); i++) {
        if (phi % i == 0) {
            if (phi / i == i) {
                factors.push_back(i);
            } else {
                factors.push_back(i);
                factors.push_back(phi / i);
            }
        }
    }
    for (int r = 2; r <= p; r++) {
        bool flag = false;
        for (int i = 0; i < factors.size(); i++) {
            if (power(r, phi / factors[i], p) == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Primitive root of " << p << " is: " << r << endl;
            return;
        }
    }
}

int main() {
    int p;
    cout<<"Student roll no : 23497"<<endl;
    cout << "Enter a prime number: ";
    cin >> p;
    if (gcd(p, p - 1) != 1) {
        cout << p << " is not a prime number." << endl;
        return 0;
    }
    findPrimitive(p);
    return 0;
}
