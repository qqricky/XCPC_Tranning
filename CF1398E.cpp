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
set<int,greater<int> >f;
set<int,greater<int> >l;
set<int,greater<int> >tot;
bool is=0;
map<int,bool>vis;
ll sum=0;
ll tmp=0;
int val=0;
int cnt=0;
ll calc(){
    bool flag=is;
    // for(auto it=tot.begin();num<=l.size();it++,num++){
    //     if(!vis[*it]){
    //         flag=1;
    //     }
    //     tmp+=*it;
    //     val=*it;
    // }
    if(flag){
        return sum+tmp;
    }
    if(f.empty()){
        return sum+tmp-val;
    }
    else if(l.empty()){
        return sum;
    }
    return sum+tmp-val+*(f.begin());
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tp,x;
        cin>>tp>>x;
        if(tp==0){
            if(x>0){
                f.insert(x);
                tot.insert(x);
                sum+=x;
            }
            else{
                f.erase(-x);
                tot.erase(-x);
                sum+=x;
            }
        }
        else{
            if(x>0){
                l.insert(x);
                tot.insert(x);
                sum+=x;
                vis[x]=1;
            }
            else{
                l.erase(-x);
                tot.erase(-x);
                sum+=x;
                vis[-x]=0;
            }
        }
        cout<<calc()<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}