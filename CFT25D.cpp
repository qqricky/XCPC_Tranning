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
vector<int>v;
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        a[i]=(int)ch;
    }
    for(int i=0;i<(1<<n);i++){
        sum=0;
        for(int j=0;j<=n-1;j++){
            if((i>>j)&1){
                sum+=a[j];
            }
        }
        v.push_back(sum);
    }
    sort(v.begin(),v.end());
    for(ll x:v){
        cout<<x<<' ';
    }
    cout.flush();
    system("pause");
    return 0;
}