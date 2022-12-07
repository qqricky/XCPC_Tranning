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
int dis(int x,int y,int a,int b){
    return (abs(a-x)+abs(y-b));
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    if(dis(a,b,1,1)<=n-1){
        for(int i=1;i<n;i++)cout<<'L';
        for(int i=1;i<n;i++)cout<<'U';
        for(int i=1;i<a;i++){
            cout<<'D';
        }
        for(int i=1;i<b;i++){
            cout<<'R';
        }

    }
    else if(dis(a,b,n,n)<=n-1){
        for(int i=1;i<n;i++)cout<<'R';
        for(int i=1;i<n;i++)cout<<'D';
        for(int i=1;i<=n-a;i++){
            cout<<'U';
        }
        for(int i=1;i<=n-b;i++){
            cout<<'L';
        }

    }
    else if(dis(a,b,1,n)<=n-1){
        for(int i=1;i<n;i++)cout<<'R';
        for(int i=1;i<n;i++)cout<<'U';
        for(int i=1;i<a;i++){
            cout<<'D';
        }
        for(int i=1;i<=n-b;i++){
            cout<<'L';
        }

    }
    else{
        for(int i=1;i<n;i++)cout<<'L';
        for(int i=1;i<n;i++)cout<<'D';
        for(int i=1;i<=n-a;i++){
            cout<<'U';
        }
        for(int i=1;i<b;i++){
            cout<<'R';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}