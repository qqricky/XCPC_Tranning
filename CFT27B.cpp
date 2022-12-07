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
int sum[1070];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str1,str2;
        cin>>str1>>str2;
        str1=' '+str1+' ';
        str2=' '+str2+' ';
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+(str1[i]==str2[i]);
        }
        int ans=sum[n];
        int ansl=1,ansr=1;
        for(int i=1;i<=n;i++){
            int cnt=0;
            if(i+1>n)continue;
            for(int l=i,r=i+1;r<=n&&l>=1;l--,r++){
                cnt+=(str1[l]==str2[r]);
                cnt+=(str1[r]==str2[l]);
                // if(l==2&&r==7){
                //     cout<<"//////////////////////"<<cnt<<endl;
                // }
                // if(r==i){
                //     if(sum[i-1]+sum[n]-sum[i+1]+cnt>ans){
                //         ans=sum[i-1]+sum[n]-sum[i+1]+cnt;
                //         ansl=i,ansr=i+1;
                //     }
                // }
                if(sum[l-1]+sum[n]-sum[r]+cnt>ans){
                    ans=sum[l-1]+sum[n]-sum[r]+cnt;
                    ansl=l,ansr=r;
                }
                else if(sum[l-1]+sum[n]-sum[r]+cnt==ans){
                    if((r-l+1)<(ansr-ansl+1)){
                        ansl=l,ansr=r;
                    }
                }
            }
            cnt=(str1[i]==str2[i]);
            for(int j=1;i-j>=1&&i+j<=n;j++){
                cnt+=(str1[i-j]==str2[i+j]);
                cnt+=(str1[i+j]==str2[i-j]);
                if(sum[i-j-1]+sum[n]-sum[i+j]+cnt>ans){
                    ans=sum[i-j-1]+sum[n]-sum[i+j]+cnt;
                    ansl=i-j,ansr=i+j;
                }
                else if(sum[i-j-1]+sum[n]-sum[i+j]+cnt==ans){
                    if((2*j+1)<(ansr-ansl+1)){
                        ansl=i-j,ansr=i+j;
                    }
                }
            }
        }
        cout<<sum[n]<<' '<<ans<<' '<<ansl<<' '<<ansr<<'\n';

    }
    cout.flush();
    //system("pause");
    return 0;
}