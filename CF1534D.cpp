#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2021;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int dis[N];
bool v[N]={};
vector<int>mp[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    read(n);
    queue<int>q;
    vector<pair<int,int> >ans;
    cout<<"? "<<1<<"\n";
    cout.flush();
    int num=0;
    for(int i=1;i<=n;i++){
        read(dis[i]);
        if(dis[i]&1)num++;
    }
    if(num<n-num){
        for(int i=1;i<=n;i++){
            if(dis[i]==1){
                q.push(i);
                v[i]=1;
            }
        }
    }
    else{
        int u=1;
        v[1]=1;
        for(int i=1;i<=n;i++){
            if(dis[i]==1){
                v[i]=1;
                ans.push_back(make_pair(u,i));
            }
            else if(dis[i]==2&&!v[i]){
                v[i]=1;
                q.push(i);
            }
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        v[u]=1;
        cout<<"? "<<u<<"\n";
        cout.flush();
        for(int i=1;i<=n;i++){
            read(dis[i]);
            if(dis[i]==1){
                v[i]=1;
                ans.push_back(make_pair(u,i));
            }
            else if(dis[i]==2&&!v[i]){
                v[i]=1;
                q.push(i);
            }
        }
    }
    cout<<"!\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<' '<<ans[i].second<<"\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}