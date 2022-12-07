#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    string a;
    string ss;
    string aa;
    cin>>a>>aa;
    for (int i = 1; i < a.length(); i++) {
        if((a[i]-'0')%2==(a[i-1]-'0')%2){
            if(a[i]>=a[i-1]){
                s+=a[i];
            }
            else{
                s+=a[i-1];
            }
        }
        // if (a[i] % 2 == a[i-1] % 2) {
        //     s += max(a[i], a[i-1]);
        // }
    }
    for (int i = 1; i < aa.length(); i++) {
        if((aa[i]-'0')%2==(aa[i-1]-'0')%2){
            if(aa[i]>=aa[i-1]){
                ss+=aa[i];
            }
            else{
                ss+=aa[i-1];
            }
        }
    }
    cout<<s<<'\n';
    if(s!=ss){
        cout<<ss<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}