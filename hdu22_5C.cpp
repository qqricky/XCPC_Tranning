#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(3)
const int N=1e6+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int from[N][27];
int pos[27];
int f[2][5];
int num[30];
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        string str;
        cin>>str;
        n=str.length();
        memset(num,0,sizeof(num));
        for(char ch:str){
            num[ch-'a']++;
        }
        str=' '+str;
        int ans=INF;
        int now=0;
        int comp=0;
        for(int s=0;s<=25;s++){
            for(int k=0;k<=25;k++){
                int cnt=num[s];
                if(s!=k)cnt+=num[k];
                if(cnt<n/100)continue;
                memset(f,0,sizeof(f));
                now=1;
                for(int i=1;i<=n;i++){
                    if(str[i]-'a'==s||str[i]-'a'==k){
                        int pre=now^1;
                        for(int j=1;j<=4;j++){
                            f[now][j]=f[pre][j];
                            if(j==1){
                                if(str[i]=='a'+s){
                                    f[now][j]=max(f[now][j],f[pre][4]+1);
                                    if(f[pre][3])
                                    f[now][j]=max(f[now][j],f[pre][3]);
                                }
                            }else if(j==2){
                                if(str[i]=='a'+k){
                                    if(f[pre][j-1])
                                    f[now][j]=max(f[now][j],f[pre][j-1]+1);
                                    f[now][j]=max(f[now][j],f[pre][4]);
                                }
                            }else if(j==3){
                                if(str[i]=='a'+k){
                                    if(f[pre][2])
                                    f[now][j]=max(f[now][j],f[pre][2]+1);
                                    if(f[pre][1])
                                    f[now][j]=max(f[now][j],f[pre][1]);
                                }
                            }else{
                                if(str[i]=='a'+s){
                                    if(f[pre][3])
                                    f[now][j]=max(f[now][j],f[pre][3]+1);
                                    if(f[pre][2])
                                    f[now][j]=max(f[now][j],f[pre][2]);
                                }
                            }
                        }
                        ans=min(ans,n-f[now][4]);
                        now^=1;
                    }
                }
                // int res=0;
                // int now=pos[j];
                // while(now<=n){
                //     res++;
                //     int tp=res%4;
                //     if(tp==0){
                //         now=ne[now][j];
                //     }else if(tp==1){
                //         now=ne[now][k];
                //     }else if(tp==2){
                //         now=ne[now][k];
                //     }else{
                //         now=ne[now][j];
                //     }
                // }
                // while(res%4){
                //     res--;
                // }
                // ans=max(ans,res);
            }
        }
        cout<<ans<<'\n';
        cout<<fixed<<setprecision(6)<<(double)clock()/CLOCKS_PER_SEC<<endl;
    }
    // cout.flush();
    // system("pause");
    return 0;
}