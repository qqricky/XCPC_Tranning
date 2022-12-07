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
bool vis[202]={};
char s[202];
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
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        string str;
        cin>>str;
        int now=50;
        bool flag=1;
        int st=50,ed=50;
        s[now]=str[0];
        vis[str[0]-'a']=1;
        for(int i=1;i<str.length();i++){
            if(s[now-1]==str[i]){
                now--;
            }
            else if(s[now+1]==str[i]){
                now++;
            }
            else{
                if(vis[str[i]-'a']){
                    flag=0;
                    break;
                }
                if(s[now+1]=='\0'){
                    now++;
                    s[now]=str[i];
                    vis[str[i]-'a']=1;
                }
                else if(s[now-1]=='\0'){
                    now--;
                    s[now]=str[i];
                    vis[str[i]-'a']=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
            st=min(st,now);
            ed=max(ed,now);
        }
        if(flag){
            cout<<"YES\n";
            for(int i=st;i<=ed;i++)cout<<s[i];
            for(int i='a';i<='z';i++){
                if(!vis[i-'a']){
                    cout<<(char)(i);
                }
            }
            cout<<'\n';
        }
        else{
            cout<<"NO\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}