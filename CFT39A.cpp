#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll val[N];
struct node
{
    ll val;
    int id;
    bool operator<(const node b)const{
        return val<b.val;
    }
}nd[N];
bool vis[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    ll n;
    //n=1000;
    cin>>n;
    ll sum=0;
    priority_queue<node>q;
    // val[1]=n-1;
    // val[2]=n-1;
    // for(int i=3;i<=n;i++){
    //     val[i]=n-3;
    // }
    // val[3]=n-7;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        q.push((node){val[i],i});
    }
    sort(val+1,val+n+1,greater<int>());
    // bool flag=1;
    // for(int i=1;i<=n;i++){
    //     if(val[i]+sum<n-1){
    //         flag=0;
    //         break;
    //     }
    //     ll x=val[i]+sum;
    //     ll y=x/(n-1);
    //     sum+=y;
    // }
    // if(flag){
    //     cout<<"Recurrent";
    //     return 0;
    // }
    ll acu=0;
    int num=0;
    while(q.top().val+acu>=n-1){
        int rk=q.top().id;
        num+=1-vis[rk];
        vis[rk]=1;
        if(num==n){
            cout<<"Recurrent";
            return 0;
        }
        ll x=q.top().val+acu;
        //cout<<x<<endl;
        q.pop();
        ll y=x/(n-1);
        acu+=y;
        x-=y*(n-1)+acu;
        q.push((node){x,rk});
    }
    while(q.size()){
        node k=q.top();
        q.pop();
        val[k.id]=k.val+acu;
    }
    for(int i=1;i<=n;i++)cout<<val[i]<<' ';
    //cout<<endl;
    //cout<<"!!!!!!!!"<<num<<endl;
    cout.flush();
    system("pause");
    return 0;
}