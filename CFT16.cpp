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
int x[N];
int cnt[7]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num[8];
    for(int i=1;i<=6;i++){
        cin>>num[i];
    }
    bool flag=1;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++){
        unordered_map<int,int>mp;
        if(x[i]>=100&&num[6]>0){
            int cnt=min(x[i]/100,num[6]);
            num[6]-=cnt;
            x[i]-=cnt*100;
            mp[100]++;
        }
        while(x[i]>=50&&num[5]>0){
            int cnt=min(x[i]/50,num[5]);
            num[5]-=cnt;
            x[i]-=cnt*50;
            mp[50]++;
        }
        // if(x[i]%20==0&&x[i]/20<=num[4]){
        //     num[4]-=x[i]/20;
        //     x[i]=0;
        // }
        while(x[i]>=20&&num[4]>0){
            int cnt=min(x[i]/20,num[4]);
            num[4]-=cnt;
            x[i]-=cnt*20;
            mp[20]++;
        }
        while(x[i]>=10&&num[3]>0){
            int cnt=min(x[i]/10,num[3]);
            num[3]-=cnt;
            x[i]-=cnt*10;
            mp[10]++;
        }
        while(x[i]>=5&&num[2]>0){
            int cnt=min(x[i]/5,num[2]);
            num[2]-=cnt;
            x[i]-=cnt*5;
            mp[5]++;
        }
        while(x[i]>=1&&num[1]>0){
            int cnt=min(x[i]/1,num[1]);
            num[1]-=cnt;
            x[i]-=cnt*1;
            mp[1]++;
        }
        if(x[i]>0){
            flag=0;
            break;
        }
        // if(x[i]>0){
        //     int cnt=x[i]/20;
        //     if(x[i]%20){
        //         flag=0;
        //         break;
        //     }
        //     if(cnt>=num[4]){
        //         x[i]=0;
        //         num[4]-=cnt;
        //     }
        //     else{
        //         flag=0;
        //         break;
        //     }
        // }
    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
    cout.flush();
    //system("pause");
    return 0;
}