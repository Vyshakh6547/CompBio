#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'A') {
            s[i] = 'T';
        }
        else if(s[i] == 'T') {
            s[i] = 'A';
        }
        else if(s[i] == 'C') {
            s[i] = 'G';
        }
        else if(s[i] == 'G') {
            s[i] = 'C';
        }
    }
    cout << s;
    cout << endl;
    return 0;
}