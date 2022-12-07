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
    int l,r;
}nd[N];
bool cmp(node a,node b){
    return (a.r-a.l)<(b.r-b.l);
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
        int n,k;
        cin>>n>>k;
        string str;
        str='L'+str;
        cin>>str;
        int cnt=0;
        int st=1;
        while(st<=str.length()&&str[st]=='L'){
            st++;
        }
        int ed=str.length()-1;
        while(ed>=1&&str[ed]=='L'){
            ed--;
        }
        int pos=st;
        while(pos<ed){
            int l=pos;
            pos++;
            while(pos<str.length()&&str[pos]=='L'){
                pos++;
            }
            if(pos-l-1==0){
                continue;
            }
            nd[++cnt].l=l+1;
            nd[++cnt].r=pos-1;
        }
    }
    cout.flush();
    system("pause");
    return 0;
}