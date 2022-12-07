#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
double pi=acos(-1);
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int go(int n,double a,int k){
    if(k==0)return n;
    if(n==4){
        return go(n,a/3,k-1);
    }else if(n==6){
        return go(8,a/sqrt(2),k-1);
    }else if(n==8){
        return go(6,a/(2*sqrt(2)),k-1);
    }else if(n==12){
        return go(20,a,k-1);
    }else if(n==20){
        return go(12,a,k-1);
    }else{
        return 0;
    }
}
double get(int n,double a,int k){
    if(k==0)return a;
    if(n==4){
        return get(n,a/3.0,k-1);
    }else if(n==6){
        return get(8,a/sqrt(2),k-1);
    }else if(n==8){
        return get(6,a*(2*sqrt(2))/3.0,k-1);
    }else if(n==12){
        a/=3.0;
        return get(20,sqrt(a*a*2-a*a*2*cos(pi*3.0/5.0)),k-1);
    }else if(n==20){
        a/=3.0;
        return get(12,sqrt(a*a*2-a*a*2*cos(pi*3.0/5.0)),k-1);
    }else{
        return -1;
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,a,k;
        cin>>n>>a>>k;
        double x=get(n,a,k);
        if(x<0){
            cout<<"impossible\n";
            continue;
        }
        cout<<"possible ";
        cout<<go(n,a,k)<<' ';
        cout<<fixed<<setprecision(8)<<x<<'\n';
    }
//     cout.flush();
//     system("pause");
    return 0;
}