#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct node
{
    int p,m;
}nd[N];
bool cmp(node &a,node &b){
    if(a.m==b.m)return a.p>b.p;
    return a.m<b.m;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int>in;
        set<int>out;
        ll sum=0;
        for(int i=1;i<=n;i++){
            cin>>nd[i].m>>nd[i].p;
            in.insert(nd[i].p);
            sum+=nd[i].p;
        }
        sort(nd+1,nd+n+1,cmp);
        ll tot=nd[n].p;
        ll cnt=0;
        ll ans=1e17;
        for(int i=n;i>=1;i--){
            int num=nd[i].m-cnt;
            while(in.size()>num){
                auto it=in.end();
                it--;
                sum-=*it;
                out.insert(*it);
                in.erase(it);
            }
            ans=min(ans,tot+sum);
            tot+=nd[i].p;
            cnt++;
            if(out.count(nd[i].p)){
                out.erase(nd[i].p);
            }
            else{
                in.erase(nd[i].p);
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}