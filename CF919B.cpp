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
int rk[10700];
bool ck(int x){
    int cnt=0;
    while(x){
        cnt+=x%10;
        x/=10;
    }
    return cnt==10;
}
vector<int>v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=2e7;i++){
        if(ck(i))v.push_back(i);
    }
    int k;
    cin>>k;
    cout<<v[k-1]<<endl;
    //system("pause");
    return 0;
}
