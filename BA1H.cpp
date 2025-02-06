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
    cin >> p;
    cin >> s;
    int d;
    cin >> d;
    for(int i=0;i<s.size()-p.size();i++){
        if(hamming(s.substr(i, p.size()),p)<=d){
            cout << i << " " ;
        }
    }
    cout << endl;
    return 0;
}