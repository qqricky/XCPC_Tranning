#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
const int N=1e5+10; 
using namespace std;
ll n=2.2e9;
bool check[N+10];
int p[N+10];
int a[2000000];
void init()
{
    ll t;
    p[0]=0;
    check[1]=true;
    for(int i=2;i<=N;i++){
        if(!check[i]){
            p[++p[0]]=i;
        }
        for(int j=1;j<=p[0];j++){
            t=i*p[j];
            if(t>N)break;
            check[t]=true;
            if(i%p[j]==0)break;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ll l,r;
    while(cin>>l>>r)
    {
        int pos=1;
        memset(a,0,sizeof(a));
        int tmp=(int)sqrt((double)r);
        if(l==1)a[0]=1;
        while(p[pos]<=tmp)
        {
            int k;
            if(l%p[pos]==0)k=0;
            else if(l<p[pos])k=p[pos]-l;
            else k=p[pos]-(l%p[pos]);
            if(l<=p[pos])a[k]=0;
            else a[k]=1;
            for(ll i=1;l+k+i*p[pos]<=r;i++){
                //cout<<l+k+i*p[pos]<<endl;
                a[k+i*p[pos]]=1;
            }
            pos++;
        }
        //for(int i=0;i<=r-l;i++)if(!a[i])cout<<l+i<<endl;
        ll pre=-1;
        ll ma=0;
        ll mi=N;
        int pos1=0;
        int pos2=0;
        for(ll i=0;i<=r-l;i++){
            if(!a[i]){
                if(pre!=-1){
                    if(i-pre>ma){
                        ma=i-pre;
                        pos1=pre;
                    }
                    if(i-pre<mi){
                        mi=i-pre;
                        pos2=pre;
                    }
                }
                pre=i;
            }
        }
        if(ma==0)cout<<"There are no adjacent primes.\n";
        else{
            cout<<l+pos2<<','<<l+pos2+mi<<" are closest, ";
            cout<<l+pos1<<','<<l+pos1+ma<<" are most distant.\n";
        }
    }
    //system("pause");
    return 0;
}   