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

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,h;
    cin>>n>>m>>h;
    int s;
    int sh;
    for(int i=1;i<=m;i++){
        int tmp;
        cin>>tmp;
        if(i==h)sh=tmp;
        s+=tmp;
    }
    if(s<n){
        cout<<-1;
        return 0;
    }
    else if(sh==1){
        cout<<0;
    }
    double ans=1;
    for(int i=2-sh;i<=0;i++){
        ans=ans*(s-n+i)/(s-1+i);
    }
    cout<<fixed<<setprecision(6)<<(1-ans);
    cout.flush();
    //system("pause");
    return 0;
}