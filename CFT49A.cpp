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
    int n;
    cin>>n;
    set<int>s[110];
    for(int i=1;i<=n;i++){
        s[i].insert(i);
    }
    s[n].insert(1);
    cout<<"1 1 0\n";
    int now=1;
    while(1){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(s[now].count(j)==0){
                s[now].insert(j);
                cout<<j<<' '<<j<<' '<<now<<'\n';
                now=j;
                flag=0;
                break;
            }
        }
        if(flag)break;
    }
    cout<<"0 1 "<<n;
    cout.flush();
    //system("pause");
    return 0;
}