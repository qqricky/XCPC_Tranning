#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int ans=0;
void dfs(int now,int mx,int num){
    if(now>2022)return;
    if(num>10)return;
    if(num==10&&now==2022){
        ans++;
        cout<<ans<<endl;
        return;
    }
    for(int i=mx+1;i<=2022;i++){
        dfs(now+i,i,num+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dfs(0,0,0);
    cout<<ans;
    cout.flush();
    system("pause");
    return 0;
}