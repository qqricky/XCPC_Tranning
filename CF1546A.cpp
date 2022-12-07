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
int a[N];
int b[N];
void de(int i,int &pos)
{
    while(a[pos]>=b[pos])pos--;
    int num=min(a[i]-b[i],b[pos]-a[pos]);
    for(int j=1;j<=num;j++){
        cout<<i<<' '<<pos<<"\n";
    }
    a[i]-=num;
    a[pos]+=num;
    if(a[i]>b[i])de(i,pos);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        int sum1=0;
        int sum2=0;
        for(int i=1;i<=n;i++)read(a[i]),sum1+=a[i];
        for(int i=1;i<=n;i++)read(b[i]),sum2+=b[i];
        if(sum1!=sum2){cout<<"-1\n";continue;}
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=abs(a[i]-b[i]);
        }
        cout<<sum/2<<"\n";
        int pos=n;
        for(int i=1;i<=n;i++){
            if(a[i]>b[i]){
               de(i,pos);
            }    
        }
    }
    //cout.flush();
    //system("pause");
    return 0;
}