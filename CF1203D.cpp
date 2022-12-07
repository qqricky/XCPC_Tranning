#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=7070;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a[N],b[N];
int cnt[N];
bool mp[N][N]={};
bool v[N]={};
bool inq[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll val=a[i]^a[j];
            if((val&a[i])<val){
                mp[j][i]=1;
                cnt[j]++;
            }
            if((val&a[j])<val){
                mp[i][j]=1;
                cnt[i]++;
            }
        }
        if(cnt[i]==n-1){
            q.push(i);
            v[i]=1;
            inq[i]=1;
        }
    }
    int num=n;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        num--;
        v[u]=1;
        for(int j=1;j<=n;j++){
            if(v[j])continue;
            if(mp[j][u]){
                cnt[j]--;
                if(cnt[j]==num-1&&!inq[j]){
                    q.push(j);
                    inq[j]=1;
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(v[j])continue;
            if(cnt[j]==num-1&&!inq[j]){
                q.push(j);
                inq[j]=1;
            }
        }
    }
    ll ans=0;
    int ncnt=0;
    for(int i=1;i<=n;i++){
        if(!v[i]){
            ncnt++;
            ans+=b[i];
        }
    }
    cout<<((ncnt>1)? ans : 0);
    cout.flush();
    //system("pause");
    return 0;
}