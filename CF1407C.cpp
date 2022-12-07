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
int ask(int x,int y)
{
    cout<<"? "<<x<<' '<<y<<endl;
    int k;
    cin>>k;
    return k;
}
int ans[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int pos=1;
    for(int i=2;i<=n;i++){
        int x=ask(pos,i);
        int y=ask(i,pos);
        if(x<y){
            ans[i]=y;
        }
        else{
            ans[pos]=x;
            pos=i;
        }
    }
    ans[pos]=n;
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout.flush();
    //system("pause");
    return 0;
}