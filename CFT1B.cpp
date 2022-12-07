#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int d[500]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i];
    map<int,int>mp;
    sort(d+1,d+n+1);
    int x=d[n];
    for(int i=1;i<=n;i++){
        mp[d[i]]++;
    }
    int y=1;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            mp[i]--;
            if(i!=(x/i))mp[x/i]--;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if((it->second)>0)
        y=max(it->first,y);
    }
    cout<<x<<' '<<y<<endl;
    //system("pause");
    return 0;
}