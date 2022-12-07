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
int f[N]={};
vector<pair<int,int> >v[N];
int main()
{
    freopen("TestCase.out","r",stdin);
    freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int x,y,z;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        if(x-y<0||x+y>n)continue;
        v[x+y].push_back(make_pair(2*y,z));
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        for(auto pr:v[i]){
            f[i]=max(f[i],f[i-pr.first]+pr.second);
        }
    }
    cout<<f[n];
    cout.flush();
    //system("pause");
    return 0;
}