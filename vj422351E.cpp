#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N=1e5+10; 
using namespace std;
ull ans=0;
int x;
void dfs(ull val,int dep)
{
    if(dep>=20)return;
    if(ans)return;
    if(val%x==0){
        ans=val;
        return;
    }
    dfs(val*10,dep+1);
    dfs(val*10+1,dep+1);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //system("pause");
    cin>>x;
    while(x!=0){
        ans=0;
        dfs(1,1);
        cout<<ans<<"\n";
        cin>>x;
    }
    return 0;
}