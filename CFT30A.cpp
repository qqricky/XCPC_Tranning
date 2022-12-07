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
int n;
struct node
{
    int p,h;
    int id;
    bool operator <(const node x)const{
        return h<x.h;
    }
}nd[2][N];
bool cmp(node x,node y){
    return x.p<y.p;
}
bool cmp1(node x,node y){
    return x.h<y.h;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nd[0][i].p;
        nd[0][i].id=i;
    }
    for(int i=1;i<=n;i++)cin>>nd[0][i].h;
    for(int i=1;i<=n;i++){
        cin>>nd[1][i].p;
        nd[1][i].id=i;
    }
    for(int i=1;i<=n;i++)cin>>nd[1][i].h;
    sort(nd[0]+1,nd[0]+n+1,cmp);
    sort(nd[1]+1,nd[1]+n+1,cmp);
    multiset<node>s1;
    multiset<node>s2;
    int p1=1,p2=1;
    bool flag=1;
    vector<int>ans[2];
    for(int i=1;i<=n;i++){
        if(s1.empty()){
            s1.insert(nd[0][p1]);
            p1++;
            while(nd[0][p1-1].p==nd[0][p1].p){
                s1.insert(nd[0][p1]);
                p1++;
            }
        }
        if(s2.empty()){
            s2.insert(nd[1][p2]);
            p2++;
            while(nd[1][p2-1].p==nd[1][p2].p){
                s2.insert(nd[1][p2]);
                p2++;
            }
        }
        if(s2.size()<=s1.size()){
            auto it=s1.upper_bound(*s2.begin());
            if(it==s1.end()){
                flag=0;
                break;
            }
            ans[0].push_back(it->id);
            s1.erase(it);
            ans[1].push_back(s2.begin()->id);
            s2.erase(s2.begin());
        }else{
            auto it=s2.lower_bound(*s1.begin());
            if(it==s2.begin()){
                flag=0;
                break;
            }
            it--;
            ans[0].push_back(s1.begin()->id);
            s1.erase(s1.begin());
            ans[1].push_back(it->id);
            s2.erase(it);
        }
    }
    if(!flag){
        cout<<"impossible";
        return 0;
    }
    for(int x:ans[0])cout<<x<<' ';
    cout<<'\n';
    for(int x:ans[1])cout<<x<<' '; 
    cout.flush();
    //system("pause");
    return 0;
}