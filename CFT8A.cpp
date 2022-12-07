#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10; 
using namespace std;
const ll mod=1e6+3;
ll jie[1050020];
void pre_work()
{
    jie[1]=1;
    for(int i=2;i<=1050000;i++){
        jie[i]=(jie[i-1]*i)%mod;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    pre_work();
    while(cin>>n)
    {
        if(n>=1e6+3)cout<<0<<endl;
        else cout<<jie[n]<<endl;
    }
    //system("pause");
    return 0;
}