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
int calc(int x,int y){
    int cnt=0;
    while(x>1&&y>1){
        cnt++;
        if(x>y){
            x-=y;
        }
        else if(x<y){
            y-=x;
        }
        else{
            return INF;
        }
    }
    cnt+=(x+y-2);
    return cnt;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int ans=INF;
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++){
        ans=min(ans,calc(i,n));
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}