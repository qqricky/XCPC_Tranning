#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+90;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[1070];
int f[N];
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
        int n;
        cin>>n;
        bool flag=0;
        set<int>s;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0)flag=1;
            for(int j=1;j<i;j++){
                if(a[i]==a[j])flag=1;
            }
        }
        s.insert(0);
        for(int i=1;i<=n;i++){
            for(int x:s){
                if(s.count(x+a[i])){
                    flag=1;
                    break;
                }
            }
            vector<int>tmp;
            for(int x:s){
                tmp.push_back(x+a[i]);
            }
            for(int x:tmp){
                s.insert(x);
            }
            if(flag)break;
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}