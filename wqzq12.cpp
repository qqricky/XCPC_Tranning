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
string raw;
bool check(string str1)
{
    for(int st=0;st<raw.length();st++){
        //st表示要匹配的模式串的起点
        bool f=true;
        //匹配串与从st开始的模式串匹配
        /* eg
            模式串S 123456
            匹配串T 345612
            st=2
            则 T[0]与S[2]匹配  T[1]与S[3]匹配 以此类推
        */
        for(int i=st,j=0;j<raw.length();j++,i=(i+1)%raw.length()){
            if(str1[i]!=raw[j]){
                f=false;
                break;
            }
        }
        if(f)return true;
    }
    return false;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    raw="123456";
    cout<<check("345612")<<endl;
    system("pause");
    return 0;
}