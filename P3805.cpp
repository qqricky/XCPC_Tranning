#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1.1e7+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*f;
}
string str;
int len,len2;
char s[2*N];
int p[2*N];
int ans=0;
void init()
{
    s[0]='#';
    s[1]='#';
    for(int i=1; i<=len; i++)
    {
        s[i*2]=str[i];
        s[i*2+1]='#';
    }
    len2=len*2+1;
}
void manacher()
{
    int mid=0,mr=0;
    for(int i=1; i<=len2; i++)
    {
        if(mr>i)
            p[i]=min(p[2*mid-i],mr-i);
        else
            p[i]=1;
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]+i>mr)
        {
            mr=p[i]+i;
            mid=i;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    len=str.length();
    str=' '+str;
    init();
    manacher();
    for(int i=1;i<=len2;i++)cout<<p[i]-1<<endl;
    cout<<ans;
    system("pause");
    return 0;
}