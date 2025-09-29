#include <iostream>
#include <vector>
#include <string>
#include <iomanip>   // setw

using namespace std;

// Simple, original student-style implementation of Longest Common Substring.
// Works for any two strings (assignment assumes equal length, but this supports varying lengths).
int main() {
    string sA, sB;
    cout << "Enter first string: ";
    getline(cin, sA);
    cout << "Enter second string: ";
    getline(cin, sB);

    int rows = (int)sA.size();
    int cols = (int)sB.size();

    // table[r][c] = length of longest suffix that ends at sA[r-1] and sB[c-1]
    vector<vector<int>> table(rows + 1, vector<int>(cols + 1, 0));

    int bestLen = 0;
    int bestEndIndexInA = 0; // exclusive end index in sA where best substring finishes

    for (int r = 1; r <= rows; ++r) {
        for (int c = 1; c <= cols; ++c) {
            if (sA[r - 1] == sB[c - 1]) {
                table[r][c] = table[r - 1][c - 1] + 1;
                if (table[r][c] > bestLen) {
                    bestLen = table[r][c];
                    bestEndIndexInA = r; // r is 1-based index of where match ends
                }
            } else {
                table[r][c] = 0; // reset when characters differ
            }
        }
    }

    // Print the table in a readable grid
    cout << "\nLookup table (rows: first string, columns: second string)\n\n";
    const int W = 4;
    cout << setw(W) << ' ';
    for (int c = 0; c < cols; ++c) cout << setw(W) << sB[c];
    cout << '\n';

    for (int r = 0; r <= rows; ++r) {
        if (r == 0) cout << setw(W) << ' ';
        else cout << setw(W) << sA[r - 1];

        for (int c = 0; c <= cols; ++c) {
            cout << setw(W) << table[r][c];
        }
        cout << '\n';
    }

    // Extract one longest common substring (assignment allows returning any one if tie)
    string result;
    if (bestLen > 0) {
        result = sA.substr(bestEndIndexInA - bestLen, bestLen);
    } else {
        result = ""; // assignment guaranteed at least one shared char
    }

    cout << "\nLongest Common Substring: " << result << '\n';
    cout << "Length: " << bestLen << '\n';

    return 0;
}
