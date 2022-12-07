#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int ts=1e6;
char ch[N];
vector<int>posr[N];
vector<int>posl[N];
int delta[N]={};
int num[2*N];
int to[N];
int cnt=0;
int c[4*N+100]={};
void add(int x,int val){
    for(int i=x;i<=4*N;i+=(i&-i)){
        c[i]+=val;
    }
}
int ask(int x){
    if(x==-1)return 0;
    int res=0;
    for(int i=x;i;i-=(i&-i)){
        res+=c[i];
    }
    return res;
}
int ans[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>ch[i];
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        posl[x].push_back(i);
        posr[y].push_back(i);
    }
    int now=ts;
    for(int i=1;i<=n;i++){
        for(int id:posl[i]){
            to[id]=now;
            num[to[id]]++;
            int tmp=ask(now);
            delta[id]=-tmp;
        }
        if(ch[i]=='0'){
            cnt+=num[now];
            add(1,1);
            now++;
            add(now,-1);
        }
        else{
            now--;
            cnt-=num[now];
        }
        for(int id:posr[i]){
            num[to[id]]--;
            if(to[id]<now)cnt--;
            ans[id]=delta[id]+ask(to[id]);
        }
    }
    int anss=0;
    for(int i=1;i<=q;i++){
        anss^=ans[i];
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    cout<<anss;
    cout.flush();
    system("pause");
    return 0;
}