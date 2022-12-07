#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=0; 
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(sum>=m){
            sum=0;
            ans++;
        }
    }
    cout<<ans;
    cout.flush();
    return 0;
}