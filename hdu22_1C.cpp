#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll num[N];
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
        int n;
        cin>>n;
        bool flag=0;
        ll sum=0;
        for(int i=0;i<=n;i++){
            cin>>num[i];
            if(i<=50 && num[i]>=(1ll<<i)){
                flag=1;
            }
            sum+=num[i];
        }
        // while(sum>0){
        //     if(num[0]){
        //         flag=1;
        //         break;
        //     }
        //     // cout<<sum<<endl;
        //     int odd=1;
        //     int st=1;
        //     while(num[st]==0)
        //     {
        //         st++;
        //     }
        //     for(int i=st;i<=n;i++){
        //         if(num[i]==0){
        //             continue;
        //         }else{
        //             if(num[i]&1){
        //                 if(odd){
        //                     num[i-1]=num[i]/2;
        //                     sum-=(num[i]/2+1);
        //                     num[i]=0;
        //                 }else{
        //                     num[i-1]=num[i]/2+1;
        //                     sum-=num[i]/2;
        //                     num[i]=0;
        //                 }
        //                 odd^=1;
        //             }else{
        //                 sum-=num[i]/2;
        //                 num[i-1]=num[i]/2;
        //                 num[i]=0;
        //             }
        //         }
        //     }
        // }
        if(flag)cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    cout.flush();
    system("pause");
    return 0;
}