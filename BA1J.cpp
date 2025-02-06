#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<string> _bases = {"A","T", "C", "G"};
string complement(string s){
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            s[i] = 'T';
        }
        else if(s[i] == 'T'){
            s[i] = 'A';
        }
        else if(s[i] == 'C'){
            s[i] = 'G';
        }
        else{
            s[i] = 'C';
        }
    }
    return s;
}
vector<string> generate_kmers(int k){
    vector<string> kmers;
    if(k==1){
        return _bases;
    }
    vector<string> small_kmers = generate_kmers(k-1);
    int num_kmers = pow(4, k);
    kmers.reserve(num_kmers); 
    for (string i: small_kmers){
        for(int j = 0; j < 4; j++){
            kmers.push_back(i + _bases[j]);
        }
    }
    return kmers;
}
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
    int k;
    cin >> s;
    cin >> k;
    int d;
    cin >> d;
    vector<string> kmers = generate_kmers(k);
    unordered_map<string, int> freq;
    for(auto i: kmers){
        freq[i] = 0;
    }
    int maxfreq=0;
    set<string> result;
    for(auto i: kmers){
        // cout << i << " ";
        string comp = complement(i);
        for(int j=0;j<s.size()-k;j++){
            if(hamming(s.substr(j, k),i)<=d){
                freq[i]++;
            }
            if(hamming(s.substr(j, k),comp)<=d){
                freq[comp]++;
            }
            if(freq[i]+freq[comp]>maxfreq){
                maxfreq = freq[i]+freq[comp];
                result.clear();
                result.insert(i);
                result.insert(comp);
            }
            else if(freq[i]+freq[comp]==maxfreq){
                result.insert(i);
                result.insert(comp);
            }
        }
        // cout << freq[i] << " " << endl;
    }
    for(auto i: result){
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}