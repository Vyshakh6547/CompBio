#include <iostream>
#include <string>
using namespace std;

int patternOccurence(string s, string p) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.substr(i, p.length()) == p) {
            cout << i << " ";
        }
    }
    cout << endl;
    return count;
}
int main() {
    string s, p;
    cin >> p >> s;
    patternOccurence(s, p);
    return 0;
}