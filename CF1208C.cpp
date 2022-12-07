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
ll mp[1070][1070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int ncnt=-1;
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=n;j+=2){
            mp[i][j]=++ncnt;
            mp[i][j+1]=++ncnt;
            mp[i+1][j]=++ncnt;
            mp[i+1][j+1]=++ncnt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mp[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}