#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int hamming(string s, string p){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != p[i]){
            count++;
        }
    }
    return count;
}
int main(){
    string s;
    string p;
    cin >> s;
    cin >> p;
    cout << hamming(s, p);
    return 0;
}