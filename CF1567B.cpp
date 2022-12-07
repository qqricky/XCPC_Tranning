#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int o[N];
void init()
{
    for(int i=1;i<N;i++){
        o[i]=o[i-1]^i;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(o[a-1]==b){
            cout<<a<<endl;
            continue;
        }
        int tmp=o[a-1]^b;
        if(tmp==a){ 
            cout<<a+2<<endl;
        }
        else{
            cout<<a+1<<endl;
        }
    }
    //cout.flush();
    //system("pause");
    return 0;
}