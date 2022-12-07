#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int a[100];
int b[100];
int p[100];
int anss[100];
int ans;
int n;
int num;
int tot=0;
const double delta=0.992;
const double eps=1e-14;
int calc()
{
    int sum=0;
    for(int i=1;i<=n;i++){
        b[i]=a[p[i]];
    }
    for(int i=1;i<=num;i++){
        sum+=b[i];
    }
    for(int i=n+1;i<=2*n;i++){
        b[i]=b[i-n];
    }
    int ma=sum;
    for(int i=1;i<=n;i++){
        sum-=b[i];
        sum+=b[i+num];
        ma=max(ma,sum);
    }
    if(tot-ma>ans){
        ans=tot-ma;
        for(int i=1;i<=n;i++){
            anss[i]=b[i];
        }
    }
    return tot-ma;
}
void SA()
{
    for(double T=5000;T>=eps;T*=delta){
        int x=rand()%n+1;
        int y=rand()%n+1;
        swap(p[x],p[y]);
        int tmp=calc();
        int del=tmp-ans;
        if(del>0){
            ans=tmp;
        }
        else if(exp(-del/T)*RAND_MAX<=rand()){
            swap(p[x],p[y]);
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
    srand(time(NULL));srand(rand());srand(rand());
    cin>>n;
    num=n;
    n*=2;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=i;
        tot+=a[i];
    }
    ans=calc();
    //cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
    while((double)clock()/CLOCKS_PER_SEC<7.5)SA();
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<anss[i]<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}