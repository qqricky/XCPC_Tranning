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
int num[11]={6,2,5,5,4,5,6,3,7,6};
int rt[11]={2,2,3,2,2,1,1,2,2,2};
int lf[11]={2,0,1,0,3,3,2,0,2,3};
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
        char x,y;
        cin>>x>>y;
        int ans=num[x-'0']+num[y-'0'];
        if(x!='1'&&rt[x-'0']==lf[y-'0']){
            if(rt[x-'0']==2){
                ans-=2;
            }
            else{
                ans-=1;
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}