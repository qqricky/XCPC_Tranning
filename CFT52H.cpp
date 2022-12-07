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
struct edge
{
    int x,y;
    int id;
}nd[N];
vector<int>mp[N];
pair<int,int>va[N];
vector<tuple<int,int,int> >ans;
vector<tuple<int,int,int> >now;
int anss;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    srand(time(0));
    srand(rand());
    int val=0;
    anss=0;
    for(int i=1;i<=m;i++){
        cin>>nd[i].x;
        cin>>nd[i].y;
        nd[i].id=i;
    }
    //1
    while((double)clock()/CLOCKS_PER_SEC<0.46){
        val=0;
        random_shuffle(nd+1,nd+m+1);
        now.clear();
        for(int i=1;i<=m;i++){
            va[i].first=0;
            va[i].second=0;
        }
        for(int i=1;i<=m;i++){
            edge e=nd[i];
            int tt=rand()%2;
            //if(tt)goto sc;
            if(va[e.x].first){
                // ssc:;
                int tmp=va[e.x].second;
                now.push_back(make_tuple(e.y,e.x,tmp));
                va[tmp].first=0;
                va[tmp].second=0;
                va[e.x].first=0;
                va[e.x].second=0;
                val++;
                // if(tt)goto ed;
            }
            else if(va[e.y].first){
                // sc:;
                int tmp=va[e.y].second;
                now.push_back(make_tuple(e.x,e.y,tmp));
                va[tmp].first=0;
                va[tmp].second=0;
                va[e.y].first=0;
                va[e.y].second=0;
                val++;
                // if(tt)goto ssc;
            }
            else{
                // ed:;
                va[e.x].first=e.id;
                va[e.y].first=e.id;
                va[e.x].second=e.y;
                va[e.y].second=e.x;
            }
        }
        if(val>anss){
            anss=val;
            ans=now;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto tp:ans){
        int a,b,c;
        std::tie(a, b, c) =tp;
        cout<<a<<' '<<b<<' '<<c;
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}