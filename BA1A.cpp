#include <iostream>
#include <string>
using namespace std;

int patternCount(string s, string p) {
    int count = 0;
    for (int i = 0; i < s.length() ; i++) {
        if (s.substr(i, p.length()) == p) {
            count++;
        }
    }
    return count;
}
int main() {
    string s, p;
    cin >> s >> p;
    cout << patternCount(s, p) << endl;
    return 0;
}