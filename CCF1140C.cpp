#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct node
{
    ll a,b;
}nd[N];
bool cmp(node x,node y){
    if(x.b==y.b){
        return x.a>y.a;
    }
    return x.b>y.b;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>nd[i].a>>nd[i].b;
    }
    vector<int>v;
    sort(nd+1,nd+n+1,cmp);
    ll ans=0;
    ll kma=INF;
    ll sum=0;
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i=1;i<=k;i++){
        sum+=nd[i].a;
        q.push(nd[i].a);
        ans=max(ans,sum*nd[i].b);
    }
    for(int i=k+1;i<=n;i++){
        if(nd[i].a>q.top()){
            sum-=q.top();
            q.pop();
            q.push(nd[i].a);
            sum+=nd[i].a;
        }
        ans=max(ans,sum*nd[i].b);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}