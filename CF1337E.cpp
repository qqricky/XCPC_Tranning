#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct node
{
    double p;
    ll num;
    double avl;
    double avl2;
}nd[250];
bool cmpp(node x,node y)
{
    return x.avl<y.avl;
}
bool cmpp2(node x,node y)
{
    return x.avl2>y.avl2;
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
    while(t--)
    {
        string str;
        ll a;
        double ans=0.0;
        double sho=0.0;
        cin>>str>>a;
        a/=100;
        for(int i=1;i<=240;i++){
            cin>>nd[i].p>>nd[i].num;
            nd[i].num/=100;
            int k=nd[i].num;
            double tmp=nd[i].p*k*100*0.0003;
            if(tmp<5.0)tmp=5.0;
            nd[i].avl=(k*nd[i].p*100+tmp)/k;
            nd[i].avl2=(k*nd[i].p*100-tmp)/k;
        }
        int now=1;
        if(str=="BUY"){
            sort(nd+1,nd+241,cmpp);
            while(a>=(nd[now].num)){
                ans+=nd[now].avl*(nd[now].num);
                a-=nd[now].num;
                now++;
            }
            for(int i=now;i<=240;i++){
                if(nd[i].num>=a){
                    double tmp=nd[i].p*a*100*0.0003;
                    if(tmp<5.0)tmp=5.0;
                    nd[i].avl=(100*a*nd[i].p+tmp)/a;
                }
            }
            sort(nd+now,nd+241,cmpp);
            while(a>0){
                int k=min(a,nd[now].num);
                ans+=k*nd[now].avl;
                a-=k;
                now++;
            }
            ans=-ans;
        }
        else{
            sort(nd+1,nd+241,cmpp2);
            while(a>=(nd[now].num)){
                ans+=nd[now].avl2*(nd[now].num);
                a-=nd[now].num;
                now++;
            }
            for(int i=now;i<=240;i++){
                if(nd[i].num>=a){
                    double tmp=nd[i].p*a*100*0.0003;
                    if(tmp<5.0)tmp=5.0;
                    nd[i].avl2=(100*a*nd[i].p-tmp)/a;
                }
            }
            sort(nd+now,nd+241,cmpp2);
            while(a>0){
                int k=min(a,nd[now].num);
                ans+=k*nd[now].avl2;
                a-=k;
                now++;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<'\n';
    }
    //cout.flush();
    system("pause");
    return 0;
}