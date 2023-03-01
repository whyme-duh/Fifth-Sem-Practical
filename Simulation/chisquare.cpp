#include <iostream>
#include <cmath>

double chi_square(int observed[], int expected[], int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += pow(observed[i] - expected[i], 2) / expected[i];
    }
    return result;
}

int main() {
    int observed[] = {50, 60, 70, 80};
    int expected[] = {60, 70, 80, 90};
    int size = sizeof(observed) / sizeof(observed[0]);

    double chi_square_value = chi_square(observed, expected, size);
    std::cout << "Chi-Square Value: " << chi_square_value << std::endl;

    return 0;
}
