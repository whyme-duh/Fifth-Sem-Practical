#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;

int main() {
    srand(time(0));
    int x = N / 2, y = N / 2;
    int steps = 0;
    while (x != 0 && x != N && y != 0 && y != N) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: // move up
                y = y + 1;
                break;
            case 1: // move down
                y = y - 1;
                break;
            case 2: // move right
                x = x + 1;
                break;
            case 3: // move left
                x = x - 1;
                break;
        }
        steps++;
    }
    cout << "Steps taken: " << steps << endl;
    return 0;
}
