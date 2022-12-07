#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10;
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
int ans[2*N];
bool vis[3*N];
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
    // for(int i=0;i<=len2;i++)cout<<s[i];
    // cout<<endl<<"what   "<<endl;
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
        //cout<<i<<' '<<p[i]<<" www"<<endl;
        //if(i+p[i]>len2)cout<<"nooooooooooooooooooooooo"<<endl;
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
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        len=str.length();
        str=' '+str;
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        init();
        manacher();
        int acnt=0;
        for(int i=len2-1;i>=1;i-=2){
            //cout<<i<<' '<<p[i]<<endl;
            if(i+p[i]-1==len2||(p[i]==i)&&(vis[i+p[i]-2])){
                vis[i]=1; 
                ans[++acnt]=i/2;
            }
        }
        for(int i=acnt;i>1;i--){
            cout<<ans[i]<<' ';
        }
        cout<<ans[1];
        cout<<endl;
    }
    //cout.flush();
    system("pause");
    return 0;
}