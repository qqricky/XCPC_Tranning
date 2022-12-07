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
bool can[5070];
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
        memset(can,0,sizeof(bool)*(n+5));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int cnt0=0;
            int cnt1=0;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(a[j]>=a[i]){
                    cnt1++;
                }
                else{
                    cnt0++;
                }
            }
            if(cnt1==cnt0){
                can[i]=1;
                continue;
            }
            if(cnt1>cnt0){
                int num=0;
                for(int j=1;j<i;j++){
                    if(a[j]>=a[i]){
                        num++;
                        if(num==3){
                            num=1;
                            cnt1-=2;
                            if(cnt1==cnt0){
                                can[i]=1;
                                break;
                            }
                        }
                    }
                    else{
                        num--;
                        num=max(num,0);
                    }
                }
                num=0;
                for(int j=i+1;j<=n;j++){
                    if(a[j]>=a[i]){
                        num++;
                        if(num==3){
                            num=1;
                            cnt1-=2;
                            if(cnt1==cnt0){
                                can[i]=1;
                                break;
                            }
                        }
                    }
                    else{
                        num--;
                        num=max(num,0);
                    }
                }
            }
            else{
                int num=0;
                for(int j=1;j<i;j++){
                    if(a[j]<a[i]){
                        num++;
                        if(num==3){
                            num=1;
                            cnt0-=2;
                            if(cnt1==cnt0){
                                can[i]=1;
                                break;
                            }
                        }
                    }
                    else{
                        num--;
                        num=max(num,0);
                    }
                }
                num=0;
                for(int j=i+1;j<=n;j++){
                    if(a[j]<a[i]){
                        num++;
                        if(num==3){
                            num=1;
                            cnt0-=2;
                            if(cnt1==cnt0){
                                can[i]=1;
                                break;
                            }
                        }
                    }
                    else{
                        num--;
                        num=max(num,0);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<can[i];
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}