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
int a[N];
string str;
set<char>s;
inline int solve(){
    int num=0;
    str=' '+str;
    for(int i=1;i<str.length();i++){
        if(s.count(str[i])){
            if(s.count(str[i-1])==0){
                num++;
            }
        }
    }
    return num;
}
int f[N]={};
int g[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    s.insert('a'),s.insert('e'),s.insert('i'),s.insert('o'),s.insert('u');
    for(int i=1;i<=n;i++){
        cin>>str;
        a[i]=solve();
        //cout<<a[i]<<' ';
    }
    //cout<<endl;
    int pos1=n,pos2=n;
    int cnt1=0,cnt2=0;
    for(int i=n;i>=1;i--){
        cnt1+=a[i];
        cnt2+=a[i];
        while(cnt1>5){
            cnt1-=a[pos1];
            pos1--;
        }
        while(cnt2>7){
            cnt2-=a[pos2];
            pos2--;
        }
        if(cnt1==5){
            f[i]=pos1+1;
        }
        if(cnt2==7){
            g[i]=pos2+1;
        }
        //cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int now=f[g[f[i]]];
        if(now>0)ans++;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}