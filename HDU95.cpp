#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int n,m,k;
int ans=0;
int da[250];
int di[250];
int prob[250];
const double delta=0.992;
const double eps=1e-14;
int calc()
{
    int anss=0;
    bool v[202]={};
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;

        }
    }
    return anss;
}
void SA()
{
    for(double T=5000;T>=eps;T*=delta){
        int x=rand()%n+1;
        int y=rand()%n+1;
        if(x==y)continue;
        swap(prob[x],prob[y]);
        int tmp=calc();
        int del=tmp-ans;
        if(del<0){
            ans=tmp;
        }
        else if(exp(-del/T)*RAND_MAX<=rand()){
            swap(prob[x],prob[y+k]);
            //swap(cath[prob[x]],cath[prob[y+k]]);
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
    ans=0;
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>da[i]>>di[i];
        }
        ans=calc();
        //cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
        for(int i=1;i<=5000;i++)SA();
        cout<<ans<<'\n';
    }
    //cout.flush();
    //system("pause");
    return 0;
}