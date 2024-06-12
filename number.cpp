#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const int size = 10; // Considering numbers between 1 and 9
    array<int, size> counts = { 0 }; // Initialize counts for each number to 0
    int num;

    cout << "Enter numbers between 1 and 9 (enter 0 to stop):\n";

    // Take input until 0 is entered
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        if (num < 1 || num > 9) {
            cout << "Invalid input. Numbers must be between 1 and 9.\n";
            continue;
        }
        counts[num]++;
    }

    // Find the number with the maximum and minimum occurrences
    int maxCount = *max_element(counts.begin(), counts.end());
    int minCount = *min_element(counts.begin(), counts.end());

    // Find the numbers with maximum and minimum occurrences
    vector<int> maxNumbers, minNumbers;
    for (int i = 1; i < size; ++i) {
        if (counts[i] == maxCount) {
            maxNumbers.push_back(i);
        }
        if (counts[i] == minCount) {
            minNumbers.push_back(i);
        }
    }

    // Print the results
    cout << "Occurrences of each number:\n";
    for (int i = 1; i < size; ++i) {
        cout << "Number " << i << ": " << counts[i] << " times\n";
    }

    cout << "Number(s) with the maximum occurrence: ";
    for (int num : maxNumbers) {
        cout << num << " ";
    }
    cout << "(Occurred " << maxCount << " times)\n";

    cout << "Number(s) with the minimum occurrence: ";
    for (int num : minNumbers) {
        cout << num << " ";
    }
    cout << "(Occurred " << minCount << " times)\n";

    return 0;
}
