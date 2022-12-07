#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
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
int f[2][26][26][6];
// int from[N][26];
// int pos[50];
int num[50];
int main()
{
    freopen("1006.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        string str;
        cin>>str;
        memset(num,0,sizeof(num));
        for(char ch:str){
            num[ch-'a']++;
        }
        n=str.length();
        str=' '+str;
        // for(int i=0;i<='z'-'a';i++)pos[i]=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<='z'-'a';j++){
        //         from[i][j]=pos[j];
        //     }
        //     pos[str[i]-'a']=i;
        //     // if(str[i]-'a'<0){
        //     //     cout<<str[i]<<endl;
        //     //     cout<<"dasjkfjakls"<<endl;
        //     // }
        // }
        int ans=INF;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            int now=str[i]-'a';
            int cur=i&1;
            int pre=cur^1;[p
            for(int k=0;k<=25;k++){
                if(k==str[i]-'a')continue;
                for(int j=4;j>=1;j--){
                    if(j==2){
                        // f[cur][now][k][j]=f[cur][from[i][str[i]-'a']][k][j];
                        f[cur][now][k][j]=f[pre][now][k][j];
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][k][str[i]-'a'][1]+1);
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][k][str[i]-'a'][4]);
                    }else if(j==3){
                        // f[cur][now][k][j]=f[cur][from[i][str[i]-'a']][k][j];
                        f[cur][now][k][j]=f[pre][now][k][j];
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][now][k][2]+1);
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][k][str[i]-'a'][1]);
                    }else if(j==4){
                        // f[cur][now][k][j]=f[cur][from[i][str[i]-'a']][k][j];
                        f[cur][now][k][j]=f[pre][now][k][j];
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][k][str[i]-'a'][3]+1);
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][k][str[i]-'a'][2]);
                    }else{
                        // f[cur][now][k][j]=f[cur][from[i][str[i]-'a']][k][j];
                        f[cur][now][k][j]=f[pre][now][k][j];
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][now][k][4]+1);
                        f[cur][now][k][j]=max(f[cur][now][k][j],f[pre][k][str[i]-'a'][3]);
                    }
                }
                ans=min(ans,n-f[cur][now][k][4]);
            }
        }
        for(int j=0;j<=25;j++){
            ans=min(ans,n-(num[j]/4)*4);
        }
        std::cout<<ans<<'\n';
        cout<<fixed<<setprecision(6)<<(double)clock()/CLOCKS_PER_SEC<<endl;
    }
    // std::cout.flush();
    // std::system("pause");
    return 0;
}