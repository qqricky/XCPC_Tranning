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
struct node
{
    ll x,y,z;
    int id;
}nd[N];
int n;
bool cmpx(node a,node b){
    if(a.x==b.x){
        if(a.y==b.y){
            return a.z<b.z;
        }
        return a.y<b.y;
    }
    return a.x<b.x;
}
bool cmpy(node a,node b){
    if(a.y==b.y){
        return a.z<b.z;
    }
    return a.y<b.y;
}
bool cmpz(node a,node b){
    return a.z<b.z;
}
bool vis[N]={};
int re=0;
int solve1(int l,int r){
    for(int i=l+1;i<=r;i+=2){
        cout<<nd[i-1].id<<' '<<nd[i].id<<'\n';
    }
    if((l-r+1)&1){
        return nd[r].id;
    }else{
        return 0;
    }
}
int solve2(int l,int r){
    int rem=0;
    int lf=l;
    for(int i=l+1;i<=r;i++){
        if(nd[i].y!=nd[i-1].y){
            int tmp=solve1(lf,i-1);
            lf=i;
            if(!tmp)continue;
            if(rem){
                cout<<tmp<<' '<<rem<<'\n';
                rem=0;
            }else{
                rem=tmp;
            }
        }
    }
    int tmp=solve1(lf,r);
    if(rem&&tmp){
        cout<<tmp<<' '<<rem<<'\n';
        rem=0;
    }else if(tmp){
        rem=tmp;
    }
    return rem;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nd[i].x>>nd[i].y>>nd[i].z;
        nd[i].id=i;
    }
    sort(nd+1,nd+n+1,cmpx);
    int rem=0;
    int lf=1;
    for(int i=2;i<=n;i++){
        if(nd[i].x!=nd[i-1].x){
            int tmp=solve2(lf,i-1);
            lf=i;
            if(!tmp)continue;
            if(rem){
                cout<<tmp<<' '<<rem<<'\n';
                rem=0;
            }else{
                rem=tmp;
            }
        }
    }
    int tmp=solve2(lf,n);
    if(rem&&tmp){
        cout<<tmp<<' '<<rem<<'\n';
        rem=0;
    }else{
        rem=tmp;
    }
    // set<pair<int,int> >s;
    // ll pre=-1145140000000ll;
    // for(int i=1;i<=n;i++){
    //     if(nd[i].x!=pre){
    //         if(s.size()){
    //             auto pr=s.upper_bound(make_pair(nd[i].y,-INF));
    //             pr--;
    //             cout<<nd[i].id<<' '<<(*pr).second<<'\n';
    //             vis[nd[i].id]=1;
    //             vis[(*pr).second]=1;
    //             s.erase(pr);
    //         }else{
    //             pre=nd[i].x;
    //             s.insert(make_pair(nd[i].y,nd[i].id));
    //         }
    //     }else{
    //         s.insert(make_pair(nd[i].y,nd[i].id));
    //     }
    // }
    // s.clear();
    // int cnt=0;
    // for(int i=1;i<=n;i++){
    //     if(!vis[nd[i].id]){
    //         nd2[++cnt]=nd[i];
    //     }
    // }
    // pre=-1145140000000ll;
    // sort(nd2+1,nd2+cnt+1,cmpy);
    // for(int i=1;i<=cnt;i++){
    //     if(nd2[i].y!=pre){
    //         if(s.size()){
    //             auto pr=s.upper_bound(make_pair(nd2[i].z,-INF));
    //             pr--;
    //             cout<<nd2[i].id<<' '<<(*pr).second<<'\n';
    //             vis[nd2[i].id]=1;
    //             vis[(*pr).second]=1;
    //             s.erase(pr);
    //         }else{
    //             pre=nd2[i].y;
    //             s.insert(make_pair(nd2[i].z,nd2[i].id));
    //         }
    //     }else{
    //         s.insert(make_pair(nd2[i].z,nd2[i].id));
    //     }
    // }
    // int ncnt=0;
    // for(int i=1;i<=cnt;i++){
    //     if(!vis[nd2[i].id]){
    //         nd[++ncnt]=nd2[i];
    //     }
    // }
    // sort(nd2+1,nd2+ncnt+1,cmpz);
    // for(int i=1;i<=ncnt;i+=2){
    //     cout<<nd[i].id<<' '<<nd[i+1].id<<'\n';
    // }
    cout.flush();
    // system("pause");
    return 0;
}