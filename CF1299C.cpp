#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
double a[N];
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
    }
    int pos=1;
    while(pos<=n){
        long double val=a[pos];
        long double sum=val;
        int to=pos;
        long double avg=val;
        for(int j=pos+1;j<=n;j++){
            sum+=a[j];
            if(sum/(j-pos+1)<=avg){
                avg=sum/(j-pos+1);
                to=j;
            }
        }
        for(int i=pos;i<=to;i++){
            a[i]=avg;
        }
        pos=to+1;
    }
    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(9)<<a[i]<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}