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
        int flag=1;
        read(n);
        for(int i=1;i<=n;i++){read(a[i]);b[i]=a[i];}
        sort(b+1,b+n+1);
        unordered_map<int,int>num;
        for(int i=1;i<=n;i++){
            if(i&1)num[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(i&1){
                num[b[i]]--;
            }
        }
        for(int i=1;i<=n;i++){
            if(num[b[i]]!=0)flag=0;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}