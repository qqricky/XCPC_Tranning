#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
double delta=0.992;
double eps=1e-14;
vector<int>p;
vector<int>anss;
int a[20];
int n,k;
ll ans=0;
inline ll calc(){
    ll val=1;
    ll tmp=0;
    for(int i=n;i>=1;i--,val*=10){
        tmp+=a[i]*val;
    }
    tmp%=k;
    return tmp;
}
void SA(){
    for(double T=5000;T>=eps;T*=delta){
        int x=rand()%n+1;
        int y=rand()%n+1;
        while(x==y){
            y=rand()%n+1;
        }
        swap(p[x],p[y]);
        swap(a[x],a[y]);
        int tmp=calc();
        int del=ans-tmp;
        if(del<0){
            ans=tmp;
            anss=p;
        }
        else if(del==0){
            if(p>anss){
                anss=p;
            }
            else if(exp(-del/T)*RAND_MAX<=rand()){
                swap(p[x],p[y]);
                swap(a[x],a[y]);
            }
        }
        else if(exp(-del/T)*RAND_MAX<=rand()){
            swap(a[x],a[y]);
            swap(p[x],p[y]);
        }
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    srand(rand());
    srand(rand());
    cin>>n>>k;
    p.resize(n+1);
    anss.resize(n+1);
    for(int i=1;i<=n;i++){
        p[i]=i;
        cin>>a[i];
    }
    while((double)clock()/CLOCKS_PER_SEC<=0.85)SA();
    for(int i=1;i<=n;i++)cout<<anss[i];
    cout.flush();
    //system("pause");
    return 0;
}