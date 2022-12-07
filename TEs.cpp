#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int vis[N]={};
    vector<int>v;
    if(k==0){
        for(int i=1;i<=n;i++)cout<<i<<' ';
    }
    else if(n>=6){
        v.push_back(3);
        v.push_back(6);
    for(int i=1;i<=k;i++){
        if(i==3)continue;
        v.push_back(2*i);
        vis[2*i]=1;
    }
    v[3]=v[6]=1;
    for(int i=1;i<=n;i++)if(!vis[i])v.push_back(i);
    for(int i=0;i<n;i++)cout<<v[i]<<' ';
    }
    else if(n==5&&k==1)cout<<"1 2 4 3 5";
    else if(n==4&&n==1)cout<<"1 2 4 3";
    else cout<<-1;
    system("pause");
    return 0;
}