#include<bits/stdc++.h>
using namespace std;
bool areAnagrams(string str1, string str2){
    if(str1.length() != str2.length()) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
int main() {
    int T;
    cin >> T;
    while(T--){
        string str1, str2;
        cin >> str1 >> str2;
        if(areAnagrams(str1,str2)){
            cout << "Yes" << endl;}
        else{
            cout << "No" << endl;}
    }
    return 0;
}