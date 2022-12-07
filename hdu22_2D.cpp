#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char pos[N];
ll num[N];
char s[N];
ll cnt[N];
string str;
int n,m;
int ncnt=0;
void solve(){
    char now=str[1];
    int val=1;
    str+='#';
    for(int i=2;i<=n+1;i++){
        if(str[i]==now)val++;
        else{
            s[++ncnt]=now;
            cnt[ncnt]=val;
            now=str[i];
            val=1;
        }
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin>>str;
        str=' '+str;
        solve();
        int p1=1;
        int re=0;
        int p2=0;
        for(int i=1;i<m;i++){
            cin>>pos[i]>>num[i];
        }
        for(int i=1;i<=n;i++){
            if(pos[i]=='-'){

            }
            if(pos[i]==s[p1]){
                if(cnt[p1]<=num[i]){
                    
                }
            }
        }
    }   
    cout.flush();
    system("pause");
    return 0;
}