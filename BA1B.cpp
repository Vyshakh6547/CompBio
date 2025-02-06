#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> freqPatternCount(string s, int l) {
    int maxcount = 0;
    unordered_map<string, int> freq;
    vector<string> result;
    for (int i = 0; i < s.length(); i++) {
        if (!freq.count(s.substr(i, l))) {
            freq[s.substr(i, l)] = 1;
        }
        else {
            freq[s.substr(i, l)]++;
        }
        if(freq[s.substr(i, l)]>maxcount) {
            maxcount = freq[s.substr(i, l)];
            result.clear();
            result.push_back(s.substr(i, l));
        }
        else if(freq[s.substr(i, l)] == maxcount) {
            result.push_back(s.substr(i, l));
        }
    }
    return result;
}
int main() {
    string s;
    int k;
    cin >> s >> k;
    for(auto i: freqPatternCount(s, k)) {
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}