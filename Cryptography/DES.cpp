#include <iostream>
using namespace std;

int s1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

int main() {
    int input = 0b0110;

    int row = input >> 1 & 0b0001;
    int col = input & 0b1111;

    int output = s1[row][col];
    cout<<"Student roll no : 23497"<<endl;
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;

    return 0;
}
