#include <bits/stdc++.h>
#include <map>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ull fac[N];
ull hs[N];
const ull base=13331;
ull gethash(int l ,int r){
    return hs[r]-hs[l-1]*fac[r-l+1];
}
ull ori[N];
ull hhash(string &s)
{
    ull tmp;
    for(int i=0;i<s.length();i++){
        tmp=tmp*base+s[i];
    }
    return tmp;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    fac[0]=1;
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*base;
    hs[0]=0;
    while(t--)
    {
        int x1,y1,r1,x2,y2,r2;
        cin>>r1>>x1>>y1>>r2>>x2>>y2;
        int d;
        cin>>d;
        double R1=(-d*1.0+sqrt(1.0*d*d+2*d*d*r1*r1))/2;
        double R2=(-d*1.0+sqrt(1.0*d*d+2*d*d*r2*r2))/2;
        cout<<R1<<endl;
        cout<<R2<<endl;
    }
    
    //cout<<endl;
    //system("pause");
    return 0;
}