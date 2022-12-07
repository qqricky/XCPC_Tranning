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
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int pos2=upper_bound(a+1,a+n+1,x)-a-1;
    int pos1=lower_bound(a+1,a+n+1,x)-a;
    if(a[pos1]!=x){
        swap(pos1,pos2);
        int len1=pos1;
        int len2=n-pos2+1;
        if(len1<len2){
            cout<<len2-len1;
        }   
        else if(len1==len2){
            cout<<1;
        }
        else{
            cout<<len1-len2+1;
        }
    }
    else{
        int len1=pos1-1;
        int len2=n-pos2;
        int len=pos2-pos1+1;
        if(len1<len2){
            len1+=len;
            cout<<max(0,len2-len1);
        }
        else if(len1==len2){
            cout<<0;
        }
        else{
            len2+=len;
            cout<<max(0,len1-len2+1);
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}