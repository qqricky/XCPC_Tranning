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
ll num[27];
ll cnt2[27];
ll cnt0[27];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=26;i++)cin>>num[i];
        memset(cnt2,0,sizeof(cnt2));
        memset(cnt0,0,sizeof(cnt0));
        ll ans1=0;
        bool is=0;
        ll cnt1=0;
        ll sum=0;
        for(int i=1;i<=26;i++){
            sum+=num[i];
            cnt2[i]=num[i]/2;
            cnt0[i]=(num[i]&1);
            //cnt1+=cnt0[i];
            if(cnt2[i]>0)ans1+=2;
            else if(num[i]){
                cnt1++;
            }
        }
        if(cnt1){
            ans1++;
            is=1;
        }
        if(ans1==0){
            cout<<"0 0\n";
            continue;
        }
        else if(ans1==1){
            cout<<ans1<<' '<<sum<<'\n';
            continue;
        }
        ll ans=0;
        ll les=is;
        ll mi=INF;
        for(int i=1;i<=26;i++){
            if(cnt2[i]){
                mi=min(mi,cnt2[i]);
            }
        }
        if(is){
            ans=min(mi,cnt1);
        }
        else{
            ans=mi;
        }
        // while(1){
        //     mi=INF;
        //     for(int i=1;i<=26;i++){
        //         if(cnt2[i]){
        //             mi=min(mi,cnt2[i]);
        //         }
        //     }
        //     if(mi==INF){
        //         if(les){
        //             ans+=cnt1/les;
        //         }
        //         else{
        //             ans+=cnt1;
        //         }
        //         break;
        //     }
        //     if(les*mi>cnt1){
        //         int val=cnt1/les;
        //         ans+=val;
        //         break;
        //     }
        //     ans+=mi;
        //     cnt1-=mi*les;
        //     for(int i=1;i<=26;i++){
        //         if(cnt2[i]){
        //             cnt2[i]-=mi;
        //             if(cnt2[i]==0)les+=2;
        //         }
        //     }
        // }
        cout<<ans1<<' '<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}