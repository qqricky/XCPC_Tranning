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
int nx[N][27];
int la[27];
int n,q;
string str;
int s1[255],s2[255],s3[255];
void init(){
    for(int i=0;i<26;i++)la[i]=n+1;
    for(int i=0;i<26;i++)nx[n+1][i]=n+1;
    for(int i=n;i>=0;i--){
        for(int j=0;j<26;j++){
            nx[i][j]=la[j];
        }
        la[str[i]-'a']=i;
    }
}
int dp[255][255][255];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    cin>>str;
    str=' '+str;
    char ch;
    int x;
    init();
    memset(dp,0,sizeof(dp));
    int l1=0,l2=0,l3=0;
    while(q--){
        cin>>ch>>x;
        if(ch=='-'){
            if(x==1){
                l1--;
            }
            else if(x==2){
                l2--;
            }
            else{
                l3--;
            }
            cout<<(dp[l1][l2][l3]==n+1 ? "NO\n": "YES\n");
            //cout<<endl;
        }
        else{
            cin>>ch;
            if(x==1){
                s1[++l1]=ch-'a';
                // if(q==1){
                //     cout<<"WHAT    "<<nx[dp[l1-1][l2][l3]][ch-'a']<<endl;
                // }
                for(int j=0;j<=l2;j++){
                    for(int k=0;k<=l3;k++){
                        dp[l1][j][k]=nx[dp[l1-1][j][k]][ch-'a'];
                        if(j)
                            dp[l1][j][k]=min(dp[l1][j][k],nx[dp[l1][j-1][k]][s2[j]]);
                        if(k)
                            dp[l1][j][k]=min(dp[l1][j][k],nx[dp[l1][j][k-1]][s3[k]]);
                    }
                }
                //cout<<"www   "<<dp[l1][0][0]<<endl;
            }
            else if(x==2){
                s2[++l2]=ch-'a';
                for(int i=0;i<=l1;i++){
                    for(int k=0;k<=l3;k++){
                        dp[i][l2][k]=nx[dp[i][l2-1][k]][ch-'a'];
                        if(i)
                            dp[i][l2][k]=min(dp[i][l2][k],nx[dp[i-1][l2][k]][s1[i]]);
                        if(k)
                            dp[i][l2][k]=min(dp[i][l2][k],nx[dp[i][l2][k-1]][s3[k]]);
                    }
                }
            }
            else{
                s3[++l3]=ch-'a';
                for(int i=0;i<=l1;i++){
                    for(int j=0;j<=l2;j++){
                        dp[i][j][l3]=nx[dp[i][j][l3-1]][ch-'a'];
                        if(j)
                            dp[i][j][l3]=min(dp[i][j][l3],nx[dp[i][j-1][l3]][s2[j]]);
                        if(i)
                            dp[i][j][l3]=min(dp[i][j][l3],nx[dp[i-1][j][l3]][s1[i]]);
                    }
                }
            }
            //cout<<dp[l1][l2][l3]<<endl;
            cout<<( (dp[l1][l2][l3]==n+1) ? "NO\n" : "YES\n" );
            //cout<<endl;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}