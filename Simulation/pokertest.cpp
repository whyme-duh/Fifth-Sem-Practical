#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // the number of numbers in the sequence
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    sort(sequence.begin(), sequence.end());

    int count = 0;
    for (int i = 0; i < n; i += 5) {
        vector<int> group(sequence.begin() + i, sequence.begin() + i + 5);
        sort(group.begin(), group.end());
        bool distinct = true;
        for (int j = 0; j < 4; j++) {
            if (group[j] == group[j+1]) {
                distinct = false;
                break;
            }
        }
        if (distinct) {
            count++;
        }
    }

    double expected_count = n / 125.0;
    double chi_squared = (count - expected_count) * (count - expected_count) / expected_count;

    cout << "Chi-squared statistic: " << chi_squared << endl;

    if (chi_squared < 2.16) {
        cout << "Sequence is random." << endl;
    } else {
        cout << "Sequence is not random." << endl;
    }

    return 0;
}
