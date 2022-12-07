#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l;
    cin>>l;
    f[0]=1;
    for(int i=1;i*n<=l;i++){
        f[i*n]=1;
    }
    for(int i=l-m;i>=1;i--){
        f[i]|=f[i+m];
    }
    for(int i=n;i<=l;i++){
        f[i]|=f[i-n];
    }
    int k;
    cin>>k;
    int tmp;
    int cnt=0;
    //for(int i=1;i<=l;i++)if(f[i])cout<<i<<endl;
    for(int i=1;i<=k;i++){
        cin>>tmp;
        if(f[tmp])cnt++;
    }
    cout<<cnt<<endl;
    //system("pause");
    return 0;
}