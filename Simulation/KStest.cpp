#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double computeKS(vector<double> data, vector<double> cdf) {
    double maxDiff = 0;
    for (int i = 0; i < data.size(); i++) {
        double diff = fabs(data[i] - cdf[i]);
        maxDiff = max(maxDiff, diff);
    }
    return maxDiff;
}

int main() {
    vector<double> data = {0.1, 0.2, 0.3, 0.4, 0.5};
    vector<double> cdf = {0.05, 0.15, 0.3, 0.6, 1};

    double ks = computeKS(data, cdf);
    cout << "KS statistic: " << ks << endl;

    return 0;
}
