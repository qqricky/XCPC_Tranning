#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>v;
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    set<int>s;
    s.insert(0);
    for(int i=1;i<(1<<n);i++){
        if(!s.count(i^x)){
            v.push_back(i);
            s.insert(i);
        }
    }
    cout<<v.size()<<'\n';
    int pre=0;
    for(int x:v){
        cout<<(x^pre)<<' ';
        pre=x;
    }
    cout.flush();
    //system("pause");
    return 0;
}