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
int a[N]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    if(n==1){
        cout<<"N";
        return 0;
    }
    for(int i=0;i<=2e5;i++){
        int tmp=a[i]/2;
        a[i+1]+=tmp;
        a[i]-=tmp*2;
    }
    int sum=0;
    for(int i=0;i<=2e5;i++){
        sum+=a[i];
    }
    if(sum==2){
        cout<<"Y";
    }
    else if(sum==1){
        cout<<"Y";
    }
    else cout<<"N";
    cout.flush();
    //system("pause");
    return 0;
}