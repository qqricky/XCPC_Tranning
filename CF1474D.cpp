#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll a[N];
ll pref[N];
ll suf[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        int flag=0;
        pref[0]=0;
        pref[1]=a[1];
        a[n+1]=0;
        for(int i=1;i<=n;i++){
            if(pref[i-1]==-1)pref[i]=-1;
            else {
                pref[i]=a[i]-pref[i-1];
                if(pref[i]<0)pref[i]=-1;    
            }
        }
        if(pref[n]==0){
            cout<<"YES\n";
            continue;
        }
        suf[n]=a[n];
        suf[n+1]=0;
        for(int i=n-1;i>=1;i--){
            if(suf[i+1]==-1)suf[i]=-1;
            else{
                suf[i]=a[i]-suf[i+1];
                if(suf[i]<0)suf[i]=-1;
            }
        }
        // int l=n-1,r=1;
        // while(pref[r-1]>=0&&r<n)r++;
        // r--;
        // while(suf[l+2]>=0&&l>=1)l--;
        // l++;
        for(int i=1;i<n;i++){
            if(pref[i-1]>=0&&suf[i+2]>=0)
            if(pref[i-1]<=a[i+1]&&a[i+1]-pref[i-1]+suf[i+2]==a[i]){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        //cout<<endl;
    }
    //cout.flush();
    //system("pause");
    return 0;
}