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
int n,m;
bool vis[510]={};
vector<pair<int,int> >v;
int ask(){
    string str;
    for(int i=1;i<=m;i++){
        if(vis[i]){
            str+='1';
        }else{
            str+='0';
        }
    }
    cout<<"? "<<str<<endl;
    cout.flush();
    int ret;
    cin>>ret;
    return ret;
}
void init(){
    for(int i=1;i<=m;i++){
        vis[i]=1;
        int tmp=ask();
        vis[i]=0;
        v.push_back(make_pair(-tmp,i));
    }
    sort(v.begin(),v.end());
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)vis[i]=1;
    int ans=ask();
    for(int i=0;i<m-1;i++){
        auto pr=v[i];
        vis[pr.second]=0;
        int tmp=ask();
        if(ans-tmp==-pr.first){
            vis[pr.second]=1;
        }else{
            ans=tmp;
        }
    }
    cout<<"! "<<ans;
    cout.flush();
    // system("pause");
    return 0;
}