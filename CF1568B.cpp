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

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        set<int>s;
        while(m--){
            int _,x;
            cin>>_>>x>>_;
            s.insert(x);
        }
        int root;
        for(int i=1;i<=n;i++){
            if(s.count(i)==0){
                root=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i==root)continue;
            cout<<root<<' '<<i<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}