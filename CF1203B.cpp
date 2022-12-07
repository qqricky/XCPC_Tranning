#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    char ch;
    if(n==1&&k==1){
        cin>>ch;
        cout<<0;
        return 0;
    }
    cin>>ch;
    a[1]=ch-'0';
    if(a[1]!=1&&k>0){
        k--;
        a[1]=1;
    }
    for(int i=2;i<=n;i++){
        cin>>ch;
        a[i]=ch-'0';
        if(k>0&&a[i]!=0){
            a[i]=0;
            k--;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i];
    cout.flush();
    //system("pause");
    return 0;
}