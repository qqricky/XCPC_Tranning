#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    ll ans=1;
    for(int i=1;i<=a*b;i++){
        ans*=i;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}