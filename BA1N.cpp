#include <bits/stdc++.h>
using namespace std;
vector<string> bases = {"A", "C", "G", "T"};
vector<string> generateNeighbors(string s, int d){
    vector<string> neighbors;
    if (d == 0) {
        neighbors.push_back(s);
        return neighbors;
    }
    else{
        for(int i=0;i<s.length();i++){
            for(auto base : bases){
                if (base[0] != s[i]) {
                    string new_s = s;
                    new_s[i] = base[0];
                    vector<string> temp = generateNeighbors(new_s, d-1);
                    neighbors.insert(neighbors.end(), temp.begin(), temp.end());
                }
            }
            
        }
    }
    return neighbors;
}
int main(){
    string s;
    int d;
    cin >> s >> d;
    vector<string> neighbors = generateNeighbors(s, d);
    sort(neighbors.begin(), neighbors.end());
    neighbors.erase(unique(neighbors.begin(), neighbors.end()), neighbors.end());
    neighbors.push_back(s);
    for(auto neighbor : neighbors){
        cout << neighbor << " ";
    }
    cout << endl;
    return 0;
}