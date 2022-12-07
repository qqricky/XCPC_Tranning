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
int n,k;
struct node
{
    string str;
    int num;
    int rk;
}nd[N];
bool cmp(node x,node y){
    if(x.num==y.num){
        return x.rk<y.rk;
    }
    return x.num>y.num;
}
int tot=0;
map<string,pair<int,int> >mp;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int cnt=3*n;
    cin.get();
    for(int i=1;i<=n;i++){
        string str;
        for(int j=1;j<=3;j++){
            cnt--;
            getline(cin,str);
            mp[str].first++;
            mp[str].second=cnt;
        }
    }
    for(auto pr:mp){
        tot++;
        nd[tot].str=pr.first;
        nd[tot].num=pr.second.first;
        nd[tot].rk=pr.second.second;
    }
    sort(nd+1,nd+tot+1,cmp);
    for(int i=1;i<=k&&i<=tot;i++){
        //cout<<nd[i].num<<' '<<nd[i].rk<<' ';
        cout<<nd[i].str<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}