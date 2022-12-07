#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
queue<int>qu;
int a[N];
int ind[2*N]={};
struct state
{
    int len,link;
    int val;
    map<int,int>ch;
    int cnt;
}st[2*N];
int sz,last;
void sam_init(){
    sz=last=0;
    st[0].len=0;
    st[0].link=-1;
    st[0].val=0;
    st[0].ch.clear();
}
void sam_extend(int c){
    int cur=++sz;
    st[cur].len=st[last].len+1;
    st[cur].val=max(c,st[last].val);
    st[cur].ch.clear();
    st[cur].cnt=1;
    int p;
    for(p=last;p!=-1&&st[p].ch[c];p=st[p].link){
        st[p].ch[c]=cur;
    }
    if(p==-1)st[cur].link=0;
    else{
        int q=st[p].ch[c];
        if(st[p].len+1==st[q].len){
            st[cur].link=q;
        }
        else{
            int clone=++sz;
            st[clone].len=st[p].len+1;
            st[clone].val=max(st[p].val,c);
            for(auto x:st[q].ch){
                st[clone].ch[x.first]=x.second;
            }
            st[clone].link=st[q].link;
            for(;p!=-1&&st[p].ch[c]==q;p=st[p].link)
                st[p].ch[c]=clone;
            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sam_init();
        int n;
        cin>>n;
        ll ans=0;
        // while(qu.size())qu.pop();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sam_extend(a[i]);
        }
        for(int i=sz;i>=1;i--){
            st[st[i].link].cnt+=st[i].cnt;
            if(st[i].cnt)ans+=st[i].val;
        }
        // for(int i=1;i<=sz;i++){
        //     ans+=st[i].val;
        //     //cout<<st[i].val<<'\n';
        // }
        // while(!qu.empty()){
        //     int u=qu.front();
        //     ans+=st[u].val;
        //     qu.pop();
        //     st[st[u].link].cnt+=st[u].cnt;
        //     ind[st[u].link]--;
        //     if(ind[st[u].link]==0&&st[u].link!=0){
        //         qu.push(st[u].link);
        //     }
        // }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}