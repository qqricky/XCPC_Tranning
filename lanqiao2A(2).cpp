#include<bits/stdc++.h>
#pragma GCC optimise(3)
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int ans=0;
int to=2022;
int dfs(int sum,int mi,int num){
    if(num==10&&sum==to){
        ans++;
        // if(ans>=1e6)cout<<ans<<endl;
        return 1;
    }
    if(num>10)return 0;
    if(sum>to)return 3;
    int flag=0;
    for(int i=mi-1;i>=1;i--){
        int tmp=dfs(sum+i,i,num+1);
    }
    return flag;
}
ll f[12][2070][2070];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=2000;i>=55;i--){
        dfs(i,i,1);
        cout<<i<<' '<<ans<<endl;
    }
    cout<<ans;
    cout.flush();
    system("pause");
    return 0;
}