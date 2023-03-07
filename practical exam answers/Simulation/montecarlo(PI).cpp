#include <iostream>
#include <cmath>
#include <random>
using namespace std;
void generateRandomPoint(double &x, double &y) {
    static default_random_engine generator;
    static uniform_real_distribution<double> distribution(-1.0, 1.0);
    x = distribution(generator);
    y = distribution(generator);
}

int main() {
    int numPoints; 
    int numInsideCircle = 0;
    int radius;
    cout<<"Enter the radius of the circle : ";
    cin >> radius;
    cout<<"Enter the number of points (greater the number, greater the accuracy) : ";
    cin >> numPoints;
    for (int i = 0; i < numPoints; i++) {
        double x, y;
        generateRandomPoint(x, y);
        if (x*x + y*y <= 1.0) {
            numInsideCircle++;
        }
    }
    double area = radius^2 * numInsideCircle / numPoints;
    cout << "Estimated value of pi: " << pi << endl;
    return 0;
}
