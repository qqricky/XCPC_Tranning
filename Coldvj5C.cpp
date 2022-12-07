#include <bits/stdc++.h>

using namespace std;

void solve(int K, string s) {
    string ans;
    int del = s.length() - K;
    int len = s.length();
    for (int i = 0; i < len; ++i){
        while (ans.length()!= 0 && ans.back() > s[i] && del){
            ans.pop_back();
            del--;
        }
        ans.push_back(s[i]);
    }
    cout << ans.substr(0,K) << endl;
}

int main(){

    int K;
    string s;
    cin >> K >> s;
    solve(K, s);
    //system("pause");
    return 0;
}