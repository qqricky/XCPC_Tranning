#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int l[N];
int s[N];
int v[N];
double acu[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n)
    {
        int pos=0;
        double ma=0.0;
        double sum=0;
        cin>>l[0];
        acu[0]=0;
        for(int i=1;i<=n;i++){cin>>l[i];acu[i]=acu[i-1]+l[i];}
        for(int i=0;i<=n;i++)cin>>s[i];
        for(int i=0;i<=n;i++)cin>>v[i];
        for(int i=1;i<=n;i++){
            if((double)(s[i]+l[i]+acu[i-1])/(double)v[i]>=ma){
                pos=i;
                ma=(double)(s[i]+l[i]+acu[i-1])/v[i];
            }
        }
        int len=0;
        double ans=0;
        for(int i=1;i<pos;i++){
            len+=l[i];
        }
        //cout<<"Www"<<pos<<endl;
        //ans=(double)len/v[pos]+ma;
        ans=max(ma,(double)s[0]/(double)v[0]);
        cout<<fixed<<setprecision(7)<<ans<<endl;
    }   
    //system("pause");
    return 0;
}