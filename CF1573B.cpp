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
int ma[N];
int mi[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        mi[0]=INF;
        ma[0]=0;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            mi[i]=min(mi[i-1],tmp);
        }
        for(int i=1;i<=n;i++){
            cin>>tmp;
            ma[i]=max(ma[i-1],tmp);
        }
        int ans=INF;
        int pos=n;
        for(int i=1;i<=n;i++){
            while(ma[pos]>mi[i]){
                pos--;
            }
            pos++;
            //cout<<i<<' '<<pos<<endl;
            ans=min(ans,i+pos-2);
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}