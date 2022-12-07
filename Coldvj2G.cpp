#include <bits/stdc++.h>
#define ll long long
const int N=1e6; 
using namespace std;
bool check[N+10];
int p[N];
vector<int>ans;
bool ck(ll x)
{
    int tmp=0;
    while(x)
    {
        int k=x%10;
        x/=10;
        tmp+=k;
    }
    if(!check[tmp])return 1;
}
void init()
{
    ll t;
    p[0]=0;
    for(int i=2;i<=N;i++){
        if(!check[i]){
            p[++p[0]]=i;
            if(ck(i)||i<=7)ans.push_back(i);
        }
        for(int j=1;j<=p[0];j++){
            t=i*p[j];
            if(t>N)break;
            check[t]=true;
            if(i%p[j]==0)break;
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
    init();
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int l,r;
        cin>>l>>r;
        int cnt=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>r)break;
            if(ans[i]>=l)cnt++;
        }
        cout<<"Case #"<<j<<": "<<cnt<<endl;
    }
    //system("pause");
    return 0;
}