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
ll a[1070];
ll b[1070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll cnt=0;
        ll ncnt=0;
        ll ans=0;
        for(int i=1;i<=n;i+=2){
            b[++ncnt]=a[i]-a[i+1];
            ans+=min(a[i],a[i+1]);
            if(b[ncnt]<=0){
                ll tmp=abs(b[ncnt]);
                ll rnum=tmp;
                bool fl=1;
                for(int j=ncnt-1;j>=1;j--){
                    if(b[j]<0){
                        tmp+=abs(b[j]);
                        continue;
                    }
                    if(b[j]==0&&(tmp<=rnum))ans++;
                    else if(b[j]<=tmp){
                        if(tmp<=rnum)ans++;
                        tmp-=b[j];
                        if(tmp<=rnum){
                            ans+=rnum-tmp+1;
                        }
                    }
                    else{
                        tmp=min(tmp,rnum);
                        ans+=tmp+1;
                        break;
                    }

                }
            }
        }
        cout<<ans<<"\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}