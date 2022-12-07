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
vector<int>pos[N];
vector<int>c[N];
int a[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        pos[y].push_back(i);
        c[y].push_back(x);
    }
    bool flag=1;
    for(int i=1;i<=n;i++){
        sort(pos[i].begin(),pos[i].end());
        sort(c[i].begin(),c[i].end());
        for(int j=0;j<pos[i].size();j++){
            if(pos[i][j]!=c[i][j]){
                flag=0;
                break;
            }
        }
    }
    if(flag)cout<<"Y";
    else cout<<"N";
    cout.flush();
    //system("pause");
    return 0;
}