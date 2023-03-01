#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;

    int rn = seed;
    int size = log10(seed) + 1;
    int mid = pow(10, size / 2);

    for (int i = 0; i < 5; i++) {
        int square = rn * rn;
        rn = (square / mid) % (int) pow(10, size);
        cout << rn << endl;
    }

    return 0;
}
