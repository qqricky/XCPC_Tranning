#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int s[N];
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
        int n;
        cin>>n;
        s[0]=0;
        int flag=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=s[i-1]^a[i];
        }
        for(int i=1;i<n;i++){
            if((s[n]^s[i])==s[i]){
                flag=1;
                break;
            }
        }
        if(!flag)
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                if(s[i]==(s[j]^s[i])&&(s[n]^s[j])==s[i]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}