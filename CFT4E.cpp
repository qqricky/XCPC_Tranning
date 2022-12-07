#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int v[11]={};
int a[11][11]={};
int ans=0;
int n;
void calc(int x,int val)
{
    if(x>n){
        ans=max(ans,val);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            calc(x+1,val+a[i][x]);
            v[i]=0;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    calc(1,0);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}