#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int seed, a, c, m;
    cout << "Enter seed value: ";
    cin >> seed;
    cout << "Enter 'a' value: ";
    cin >> a;
    cout << "Enter 'c' value: ";
    cin >> c;
    cout << "Enter 'm' value: ";
    cin >> m;

    int choice;
    cout << "Enter choice (1 for float, 2 for int): ";
    cin >> choice;
    switch (choice) {
        case 1:
            for (int i = 0; i < 5; i++) {
                seed = (a * seed + c) % m;
                float rn = (float)seed / m;
                cout << rn << endl;
            }
            break;
        case 2:
            for (int i = 0; i < 5; i++) {
                seed = (a * seed + c) % m;
                cout << seed << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
            exit(1);
    }

    return 0;
}
