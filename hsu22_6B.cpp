#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int value[N]={};
void build(int id, int l, int r){
    value[id] += r-l+1;
    if(l == r) return;
    int mid = (r+l)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    return;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        build(1,1,i);
    }
    for(int i=1;i<=4*n;i++){
        cout<<i<<' '<<value[i]<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}