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
map<ll,int>mp;
map<ll,int>pos;
ll a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=62;j++){
            if((a[i]>>j)&1){
                //cout<<i<<' '<<j<<endl;
                mp[1<<j]++;
                pos[1<<j]=i;
            }
        }
    }
    int st=1;
    for(int j=62;j>=0;j--){
        if(mp[1<<j]==1){
            st=pos[1<<j];
            break;
        }
    }
    cout<<a[st]<<' ';
    for(int i=1;i<=n;i++){
        if(i==st)continue;
        cout<<a[i]<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}