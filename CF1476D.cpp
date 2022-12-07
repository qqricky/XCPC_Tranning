#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+10; 
using namespace std;
int fl[N],fr[N];
int dpl[N],dpr[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        int n;
        cin>>n>>str;
        str=' '+str+' ';
        fl[0]=0;
        fr[n+1]=0;
        dpl[0]=0;
        dpr[n+1]=0;
        dpr[n+2]=-1;
        for(int i=1;i<=n+1;i++){
            dpl[i]=1;
            if(str[i-1]!=str[i])dpl[i]=dpl[i-1]+1;
            fl[i]=1;
            if(str[i-1]=='L')fl[i]=dpl[i-1]+1;
        } 
            for(int i=n+1;i>=1;i--){
            dpr[i]=1;
            if(str[i]!=str[i+1])dpr[i]=dpr[i+1]+1;
            fr[i]=1;
            if(str[i]=='R')fr[i]=dpr[i]+1;
        }
        for(int i=1;i<=n+1;i++){
            cout<<fr[i]+fl[i]-1<<' ';
        }
        cout<<"\n";
    }
    //system("pause");
    return 0;
}