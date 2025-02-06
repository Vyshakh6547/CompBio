#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int skew;
    skew = 0;
    int minSkew=skew;
    vector<int> minSkewIndex;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'G') {
            skew++;
        }
        else if(s[i] == 'C') {
            skew--;
        }
        if(skew < minSkew) {
            minSkew = skew;
            minSkewIndex.clear();
            minSkewIndex.push_back(i+1);
        }
        else if(skew == minSkew) {
            minSkewIndex.push_back(i+1);
        }
    }
    for(int i = 0; i < minSkewIndex.size(); i++) {
        cout << minSkewIndex[i] << " ";
    }
    cout << endl;
    return 0;
}