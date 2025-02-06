#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> patternClump(string s, int k, int l, int t) {
    vector<string> clumps;
    unordered_map<string, vector<int>> occ_map; // Stores positions of each k-mer

    for (int i = 0; i <= s.length() - k; i++) {
        string pattern = s.substr(i, k);
        occ_map[pattern].push_back(i);
    }

    for (auto &entry : occ_map) {
        vector<int> &occ = entry.second;
        if (occ.size() < t) continue; // Ignore if occurrences are less than t

        // Check if there exists a window of length L containing at least t occurrences
        for (int j = 0; j <= occ.size() - t; j++) {
            if (occ[j + t - 1] - occ[j] <= l - k) { // Ensure they fit within L-length window
                clumps.push_back(entry.first);
                break; // No need to check further, this pattern is valid
            }
        }
    }

    return clumps;
}

int main() {
    string s;
    int k, l, t;
    cin >> s >> k >> l >> t;

    vector<string> result = patternClump(s, k, l, t);
    for (auto &i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
