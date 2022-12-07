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
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        a[i]=ch-'0';
    }
    a[0]=0;
    int pos;
    bool flag=0;
    for(int i=1;i<n;i++){
        if(k<=0)break;
        if(a[i]==4&&a[i+1]==7){
            if(i&1){
                k--;
                a[i+1]=4;
            }
            else{
                a[i]=7;
                k--;
                if(a[i-1]==4){
                    pos=i;
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag){
        if(k&1){
            if(a[pos]==4)a[pos]=7;
            else a[pos]=4;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i];
    cout.flush();
    //system("pause");
    return 0;
}