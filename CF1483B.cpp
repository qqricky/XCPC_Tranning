#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
ll a[N];
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
        int flag=1;
        ll m=0;
        int f1=0;
        ll ma=0;
        for(int i=1;i<=n;i++){cin>>a[i];ma=max(ma,a[i]);}
        ll d;
        int pos=1;
        if(n<=1){
            f1=1;
            goto paris;
        }
        if(a[1]<a[2])d=a[2]-a[1];
        else if(a[1]>a[2]){
            d=a[1]-a[2];
            while(pos<n&&a[pos]>a[pos+1])
            {
                if(d!=(a[pos]-a[pos+1])){
                    flag=0;break;
                }
                pos++;
            }
            if(pos==n){
                f1=1;
                goto paris;
            }
            else{
                m=a[pos+1]+d;
                if(m>=ma){
                    flag=0;
                    goto paris;
                }
                d=m-d;
                for(;pos<n;pos++){
                    if((a[pos]+d)%m!=a[pos+1]){
                        flag=0;
                        break;
                    }
                }
                if(flag)goto paris;
            }
        }
        else{
            while(a[pos]==a[pos+1]&&pos<n){
                pos++;
            }
            if(pos!=n)flag=0;
            else{
                f1=1;
                goto paris;
            }
        }
        if(flag){
            f1=0;
            int gg=1;
            for(int i=2;i<=n;i++){
                if(a[i]>a[i-1]){
                    if(a[i]-a[i-1]!=d){
                        flag=0;
                        break;
                    }
                }
                else if(a[i]<a[i-1]){
                    gg=0;
                    if(m!=0&&((a[i-1]+d-a[i])!=m)){
                        flag=0;
                        break;
                    }
                    else{
                        m=a[i-1]+d-a[i];
                        if(m>=ma){
                            flag=0;
                            goto paris;
                        }
                    }
                }
                else{
                    flag=0;
                    break;
                }
                //cout<<m<<endl;
            }
            if(gg)f1=1;
        }
        paris:;
        if(f1)cout<<0<<endl;
        else if(flag){
            cout<<m<<' '<<d<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    //system("pause");
    return 0;
}