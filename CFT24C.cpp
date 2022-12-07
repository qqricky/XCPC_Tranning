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
int n;
const ll ma=99999999;
const ll mi=-99999999;
bool vis[11]={};
ll a[11];
vector<int>v;
bool ck(ll sum){
    if(sum>ma||sum<0)return 0;
    bool fl=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            fl=0;
            vis[i]=1;
            v.push_back(a[i]);
            if(ck(sum+a[i])){
                return 1;
            }
            v.pop_back();
            vis[i]=0;
        }
    }
    if(fl)return 1;
    return 0;
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
        cin>>a[i];
    }
    if(ck(0)){
        for(int x:v){
            cout<<x<<'\n';
        }
    }
    else{
        cout<<"Error";
    }
    cout.flush();
    //system("pause");
    return 0;
}