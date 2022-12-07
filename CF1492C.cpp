#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
int f1[N],f2[N];
int f[N]={};
int F[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int pos=0;
    f1[0]=0;
    for(int i=0;i<n&&pos<m;i++){
        if(s[i]==t[pos]){
            f1[i+1]=pos+1;
            pos++;
            if(pos==m){
                for(int j=i+2;j<=n;j++)f1[j]=f1[j-1];
            }
        }
        else{
            f1[i+1]=f1[i];
        }
    }
    pos=m-1;
    f2[m]=0;
    for(int i=n;i>=0&&pos>=0;i--){
        if(s[i]==t[pos]){
            f2[i+1]=m-pos;
            pos--;
            if(pos==-1){
                for(int j=i;j>=1;j--)f2[j]=f2[j+1];
            }
        }
        else{
            f2[i+1]=f2[i+2];
        }
    }
    int ans=0;
    f[0]=100000000;
    for(int i=1;i<=n;i++){
        if(f[f1[i]]==0)f[f1[i]]=i;
    }
    for(int i=n;i>=1;i--){
        //cout<<i<<'Q'<<f[m-f2[i]]<<endl;
        ans=max(ans,i-f[m-f2[i]]);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}