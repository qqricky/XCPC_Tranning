#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll d[2*N];
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
        for(int i=1;i<=2*n;i++){
            cin>>d[i];
            if(d[i]&1||d[i]==0){
                flag=0;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        sort(d+1,d+2*n+1);
        ll sum=0;
        ll tmp=0;
        for(int i=1;i<=2*n;i+=2){
            if((d[i]!=d[i+1])||(d[i]==d[i-1])){
                flag=0;
                break;
            }
            if(i!=1 && (d[i]-d[i-1])%(i-1)!=0){
                //cout<<(d[i]-d[i-1])<<endl;
                //cout<<(i+1)/2<<endl;
                flag=0;
                break;
            }
            if(i!=1)tmp+=(d[i]-d[i-1])/(i-1);
            sum+=tmp;
        }
         sum*=2;
        // cout<<d[1]<<'Q'<<sum<<endl;
        // cout<<d[1]-sum<<endl;
        // cout<<(d[1]-sum)/(2*n)<<endl;
        if((d[1]-sum)<(2*n)||(d[1]-sum)%(2*n)!=0)flag=0;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
}