#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a[N];
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
        int flag=1;
        for(int i=1;i<=n;i++){
            read(a[i]);
            a[i]+=(1e9+1);
        }
        unordered_map<ll,ll>nex;
        unordered_map<ll,ll>pre;
        ll last=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]==last)continue;
            if(a[i]>last){
                if(nex[last]==0){
                    nex[last]=a[i];
                    pre[a[i]]=last;
                    last=a[i];
                    continue;
                }
                if(nex[last]==a[i]){
                    last=a[i];
                    continue;
                }
                if(nex[last]<a[i]){
                    flag=0;
                    break;
                }
                nex[a[i]]=nex[last];
                pre[nex[last]]=a[i];
                nex[last]=a[i];
                pre[a[i]]=last;
            }
            else{
                if(pre[last]==0){
                    pre[last]=a[i];
                    nex[a[i]]=last;
                    last=a[i];
                    continue;
                }
                if(pre[last]==a[i]){
                    last=a[i];
                    continue;
                }
                if(pre[last]>a[i]){
                    flag=0;
                    break;
                }
                nex[pre[last]]=a[i];
                pre[a[i]]=pre[last];
                nex[a[i]]=last;
                pre[last]=a[i];
            }
            last=a[i];
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}