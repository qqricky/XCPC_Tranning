#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int num[N]={};
bool can[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        num[x]++;
    }
    for(int i=1;i<=2e5;i++){
        if(num[i]>1)can[1]=1;
        if(!num[i])continue;
        for(int j=2;i*j<=2e5;j++){
            if(num[i*j])can[j]=1;
        }
    }
    while(q--){
        int val;
        cin>>val;
        if(can[val])cout<<"YES\n";
        else cout<<"NO\n";
    }
    // cout.flush();
    // system("pause");
    return 0;
}